#include <cstdio>
#include <cstdlib>
#include <chrono>

int main() {
    system("g++ data.cpp -o data");
    system("./data > data.in");
    system("g++ code.cpp -o code -O2");

    auto start = std::chrono::high_resolution_clock::now();
    system("./code < data.in > code.out");
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    printf("time = %ld ms\n", duration);

    return 0;
}