#include <cstdio>
#include <random>
#include <ctime>

const int maxn = 10;
const int maxm = 10;

const int maxv = 1000;

int main() {
    srand(time(nullptr));
    int n = rand() % maxn + 1;
    int m = rand() % maxm + 1;
    printf("%d %d\n", n, m);

    std::default_random_engine e(time(nullptr));
    std::uniform_int_distribution<int> v(1, maxv);
    std::uniform_int_distribution<int> u(1, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", v(e));
    }
    printf("\n");

    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", u(e), u(e));
    }

    return 0;
}