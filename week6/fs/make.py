import subprocess

subprocess.call("make clean", shell=True)
subprocess.call("make", shell=True)
subprocess.call("./bin/hw7", shell=True)
