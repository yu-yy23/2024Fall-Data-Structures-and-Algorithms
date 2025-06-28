#include <cstdio>
#include <random>
#include <ctime>

const int N = 500000;
const int M = 500000;

int main() {
    srand(time(0));
    int n = 2047;
    
    char* out = new char[2 * n + 1];

    for (int i = 0; i < n; i++) {
        out[i] = rand() % 26 + 'A';
        while (i > 1 && out[i] == out[i - 1] && out[i] == out[i - 2]) {
            out[i] = rand() % 26 + 'A';
        }
    }
    if (out[n - 1] == 'A') out[n] = 'B';
    else out[n] = 'A';
    out[n + 1] = 'A';

    for (int i = n + 2; i < 2 * n; i++) {
        out[i] = rand() % 26 + 'A';
        while (i > n + 2 && out[i] == out[i - 1] && out[i] == out[i - 2]) {
            out[i] = rand() % 26 + 'A';
        }
    }

    out[2 * n] = '\0';

    printf("%s\n", out);

    int m = 1;
    printf("%d\n", m);

    printf("%d %c\n", n + 2, 'A');

    delete[] out;

    return 0;
}