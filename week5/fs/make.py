import subprocess

subprocess.call("make clean", shell=True)
subprocess.call("make 2> error_msg.txt", shell=True)

subprocess.call("./bin/ut_test", shell=True)

with open('error_msg.txt' , 'r') as d:
    lines = d.readlines(10000)
    count = 0
    for line in lines:
        if ("error" in line)or(count<=3):
            print(line)
            count += 1
        if (count == 3):
            break
        if not lines: break
