#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>

const int low = 10;
const int high = 200000;
const unsigned int max = pow(2, 31);

int main() {
    srand(time(0));

    int n = rand() % (high - low) + low + 1;
    int m = rand() % (high - low) + low + 1;

    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", rand() % (max - 1) + 1);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", rand() % (max - 1) + 1);
    }
    printf("\n");

    printf("%d\n", m);
    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", rand() % max, rand() % max);
    }

    return 0;
}