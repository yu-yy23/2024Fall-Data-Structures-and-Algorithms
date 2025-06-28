#include <cstdio>
#include <cstdlib>

int times = 100;

int main() {
    system("g++ data.cpp -o data");
    system("g++ code.cpp -o code -O2");
    system("g++ reference.cpp -o reference -O2");

    while (times--) {
        system("./data > data.in");
        system("./code < data.in > code.out");
        system("./reference < data.in > reference.out");

        if (system("diff code.out reference.out -w") != 0) {
            printf("WA\n");
            exit(1);
        }
    }
    
    return 0;
}