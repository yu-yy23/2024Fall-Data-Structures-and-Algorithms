import subprocess
import time

def test():
    # 生成输入数据
    data_gen = subprocess.run(["./data.exe"], capture_output=True, text=True)
    input_data = data_gen.stdout

    # 将输入数据写入文件
    with open("data.in", "w") as f:
        f.write(input_data)

    # 运行 code.cpp
    start_time = time.time()
    code_run = subprocess.run(["./code.exe"], input=input_data, capture_output=True, text=True)
    code_time = time.time() - start_time
    code_output = code_run.stdout

    # 将 code.cpp 的输出写入文件
    with open("code.out", "w") as f:
        f.write(code_output)

    # 记录运行时间
    print(f"Code program runtime: {code_time:.6f} seconds")

if __name__ == "__main__":
    data_gen = subprocess.run(["g++", "absolute_data.cpp", "-o", "data.exe"], check=True)
    subprocess.run(["g++", "code.cpp", "-o", "code.exe"], check=True)
    times = 10000
    for i in range(times):
        test()
        print(f"Test {i+1}/{times} finished.")
        print()