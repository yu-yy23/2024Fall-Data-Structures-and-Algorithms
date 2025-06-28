#include <cstdio>
#include <cstdlib>
#include <chrono>

int main() {
    system("g++ data.cpp -o data");
    system("./data > data.in");
    system("g++ 03.cpp -o code -O2");
    system("g++ reference.cpp -o reference -O2");

    auto start = std::chrono::high_resolution_clock::now();
    system("./code < data.in > code.out");
    auto end = std::chrono::high_resolution_clock::now();
    auto start2 = std::chrono::high_resolution_clock::now();
    system("./reference < data.in > reference.out");
    auto end2 = std::chrono::high_resolution_clock::now();

    if (system("diff code.out reference.out -w") != 0) {
        printf("WA\n");
    } else {
        printf("AC\n");
    }
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();
    printf("time = %ld ms\nreference time = %ld ms\n", duration, duration2);

    return 0;
}