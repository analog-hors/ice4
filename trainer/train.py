import torch, numpy, ctypes, json, subprocess, convert, os

from time import time, strftime

BATCH_SIZE = 16384
DATASET_PATH = "data/frzn-big3.bin"

subprocess.run(["cargo", "build", "--release", "-p", "trainer"])

PARSELIB = ctypes.cdll.LoadLibrary("../target/release/libtrainer.so")

PARSELIB.linear_feature_count.argtypes = []
PARSELIB.linear_feature_count.restype = ctypes.c_ulong
LINEAR_FEATURE_COUNT = int(PARSELIB.linear_feature_count())

PARSELIB.king_safety_feature_count.argtypes = []
PARSELIB.king_safety_feature_count.restype = ctypes.c_ulong
KING_SAFETY_FEATURE_COUNT = int(PARSELIB.king_safety_feature_count())

# PARSELIB.decode_data.argtypes = [
#     ctypes.POINTER(ctypes.c_ubyte),
#     ctypes.POINTER(ctypes.c_float),
#     ctypes.POINTER(ctypes.c_float),
#     ctypes.c_size_t,
# ]
PARSELIB.decode_data.restype = ctypes.c_bool

def batch_loader():
    with open(DATASET_PATH, "rb") as dataset:
        while True:
            data = dataset.read(BATCH_SIZE * 32)
            batch_size = len(data) // 32
            if batch_size == 0:
                return

            linear = numpy.zeros((batch_size, LINEAR_FEATURE_COUNT), dtype=ctypes.c_float)
            king_safety = numpy.zeros((batch_size, KING_SAFETY_FEATURE_COUNT), dtype=ctypes.c_float)
            phase = numpy.zeros((batch_size, 1), dtype=ctypes.c_float)
            target = numpy.zeros((batch_size, 1), dtype=ctypes.c_float)

            result = PARSELIB.decode_data(
                data,
                numpy.ctypeslib.as_ctypes(linear),
                numpy.ctypeslib.as_ctypes(king_safety),
                numpy.ctypeslib.as_ctypes(phase),
                numpy.ctypeslib.as_ctypes(target),
                batch_size
            )
            assert result

            yield (
                torch.from_numpy(linear),
                torch.from_numpy(king_safety),
                torch.from_numpy(phase),
                torch.from_numpy(target),
            )

class Model(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.mg = torch.nn.Linear(LINEAR_FEATURE_COUNT, 1, bias=False)
        torch.nn.init.zeros_(self.mg.weight)
        self.eg = torch.nn.Linear(LINEAR_FEATURE_COUNT, 1, bias=False)
        torch.nn.init.zeros_(self.eg.weight)

    def forward(self, linear: torch.Tensor, king_safety: torch.Tensor, phase: torch.Tensor):
        mg = self.mg(linear)
        eg = self.eg(linear)

        score = torch.lerp(eg, mg, phase)

        return torch.sigmoid(score)

train_id = strftime("%Y-%m-%d-%H-%M-%S-") + os.path.splitext(os.path.basename(DATASET_PATH))[0]
model = Model()
optimizer = torch.optim.Adam(model.parameters(), lr=0.01)

print(train_id)

loss = 0
for epoch in range(15):
    if epoch in [8, 12]:
        optimizer.param_groups[0]["lr"] /= 10

    iters = 0
    running_loss = 0
    poses = 0
    start = time()
    for linear, king_safety, phase, target in batch_loader():
        optimizer.zero_grad()
        output = model(linear, king_safety, phase)
        loss = torch.mean(torch.abs(output - target) ** 2.6)
        loss.backward()
        optimizer.step()

        running_loss += loss.item()
        iters += 1
        poses += target.shape[0]

    loss = running_loss / iters
    print(f"epoch {epoch+1: 2}:    loss {loss:.4g}    pos/s {round(poses / (time() - start))}")

data = {
    "train_id": train_id, "loss": loss, "params": {
        name: param.detach().cpu().numpy().tolist()
        for name, param in model.named_parameters()
    }
}
with open(f"models/{train_id}.json", "w") as json_file:
    json.dump(data, json_file)

convert.dump_result(data)
