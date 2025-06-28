#include <cstdio>
#include <cstdlib>

int times = 100;

int main() {
    system("g++ data.cpp -o data");
    system("g++ 10.cpp -o code -O2");
    system("g++ reference.cpp -o reference -O2");

    while (times--) {
        system("./data > data.in");
        system("./code < data.in > code.out");
        system("./reference < data.in > reference.out");

        if (system("diff code.out reference.out -w") != 0) {
            printf("%d WA\n", times);
            exit(1);
        } else {
            printf("%d AC\n", times);
        }
    }
    
    return 0;
}