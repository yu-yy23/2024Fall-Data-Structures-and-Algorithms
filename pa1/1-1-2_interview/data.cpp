#include <cstdio>
#include <cstdlib>
#include <ctime>

const int low = 100000;
const int high = 1000000;

int main() {
    srand(time(0));
    int n = rand() % (high - low) + low + 1;
    int m = rand() % (10000000 / n) + 1;
    printf("%d %d\n", n, m);
    int start_id = rand() % 1000 + 1;
    for (int i = 0; i < n; ++i) {
        printf("%d ", start_id++);
    }
}