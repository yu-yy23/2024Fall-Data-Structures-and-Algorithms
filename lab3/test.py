import subprocess
import time
import csv
import itertools
import os
import sys

# 定义编译器和文件名
COMPILER = "g++"  # 确保 g++ 已安装并在系统路径中
SOURCE_DIR = "lab3"
SOURCE_FILES = [
    "main.cpp",
    "hashtable.cpp",
]
SOURCE_PATHS = [os.path.join(SOURCE_DIR, file) for file in SOURCE_FILES]
EXECUTABLE = "main.exe"  # Windows 下的可执行文件

# 定义参数组合
hashing_strategies = ["uneven", "uniform"]
collision_strategies = ["linear", "bidirectional", "public"]

# 输出 CSV 文件路径
OUTPUT_CSV = "lab3/run_times.csv"

def compile_program():
    """
    编译所有必要的源文件生成 main.exe。
    """
    print("正在编译源文件...")
    compile_cmd = [COMPILER, "-o", EXECUTABLE] + SOURCE_PATHS
    try:
        result = subprocess.run(compile_cmd, capture_output=True, text=True)
        if result.returncode != 0:
            print("编译失败！错误信息如下：")
            print(result.stderr)
            sys.exit(1)
        print("编译成功。\n")
    except FileNotFoundError:
        print(f"错误: 未找到编译器 {COMPILER}。请确保已安装并添加到系统 PATH 中。")
        sys.exit(1)

def run_program(hashing, collision):
    """
    运行 main.exe 并测量其运行时间。
    """
    if os.name == 'nt':  # Windows
        command = [EXECUTABLE, hashing, collision]
    else:  # Unix/Linux/MacOS
        command = [f"./{EXECUTABLE}", hashing, collision]
    print(f"运行参数: 哈希策略 = {hashing}, 碰撞策略 = {collision}")

    start_time = time.time()
    try:
        # 运行程序，重定向输入输出
        with open(os.path.join(SOURCE_DIR, "data.in"), "r") as input_file:
            result = subprocess.run(
                command,
                stdin=input_file,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                timeout=30,  # 设置超时时间（秒），根据需要调整
                cwd=SOURCE_DIR
            )
        end_time = time.time()
        run_time = end_time - start_time

        if result.returncode != 0:
            print(f"运行失败，错误信息:\n{result.stderr}\n")
            return run_time, False
        else:
            print(f"运行成功，运行时间: {run_time:.6f} 秒\n")
            return run_time, True
    except subprocess.TimeoutExpired:
        print("大于 30 秒\n")
        return None, False
    except Exception as e:
        print(f"运行过程中发生异常: {e}\n")
        return None, False

def main():
    # 检查源文件是否存在
    missing_files = [file for file in SOURCE_PATHS if not os.path.exists(file)]
    if missing_files:
        print("错误: 未找到以下源文件：")
        for file in missing_files:
            print(f" - {file}")
        sys.exit(1)

    # 编译程序
    compile_program()

    # 打开 CSV 文件并写入表头
    with open(OUTPUT_CSV, mode='w', newline='', encoding='utf-8') as csv_file:
        fieldnames = ["Hashing_Strategy", "Collision_Strategy", "Run_Time_Seconds", "Status"]
        writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        writer.writeheader()

        # 遍历所有参数组合
        for hashing, collision in itertools.product(hashing_strategies, collision_strategies):
            run_time, success = run_program(hashing, collision)
            status = "Success" if success else "Failed"

            # 写入 CSV
            writer.writerow({
                "Hashing_Strategy": hashing,
                "Collision_Strategy": collision,
                "Run_Time_Seconds": f"{run_time:.6f}" if run_time is not None else "",
                "Status": status
            })

    print(f"所有测试完成，结果保存在 {OUTPUT_CSV}。")

if __name__ == "__main__":
    main()