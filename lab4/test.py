import subprocess
import time
import sys

def test():
    # 将输入数据写入文件
    with open("data.in", "r") as f:
        input_data = f.read()

    # 测试 AVL
    start_time = time.time()
    avl_run = subprocess.run(["./avl.exe"], input=input_data, capture_output=True, text=True)
    avl_time = time.time() - start_time
    avl_output = avl_run.stdout

    with open("avl.out", "w") as f:
        f.write(avl_output)

    # 测试伸展树
    start_time = time.time()
    splay_run = subprocess.run(["./splay.exe"], input=input_data, capture_output=True, text=True)
    splay_time = time.time() - start_time
    splay_output = splay_run.stdout

    with open("splay.out", "w") as f:
        f.write(splay_output)

    # 测试红黑树
    start_time = time.time()
    redblack_run = subprocess.run(["./redblack.exe"], input=input_data, capture_output=True, text=True)
    redblack_time = time.time() - start_time
    redblack_output = redblack_run.stdout

    with open("redblack.out", "w") as f:
        f.write(redblack_output)

    # 比较输出结果
    splay_flag = False
    redblack_flag = False
    if splay_output == avl_output:
        print("Splay and AVL outputs are the same.")
        splay_flag = True
    else:
        print("Splay Wrong.")
    if redblack_output == avl_output:
        print("Red-Black and AVL outputs are the same.")
        redblack_flag = True
    else:
        print("Red-Black Wrong.")

    # 判断测试是否成功
    if splay_flag and redblack_flag:
        print("Success.")
    else:
        print("Failed.")
        exit(1)

    # 记录运行时间
    print(f"AVL: {avl_time*1000:.0f} ms")
    print(f"Splay: {splay_time*1000:.0f} ms")
    print(f"Red-Black: {redblack_time*1000:.0f} ms")

if __name__ == "__main__":
    subprocess.run(["g++", "splay.cpp", "-o", "splay.exe"], check=True)
    subprocess.run(["g++", "redblack.cpp", "-o", "redblack.exe"], check=True)
    print(f"Test started.")
    test()
    print(f"Test finished.")