#include <cstdio>
#include <random>
#include <ctime>

int dim = 2;
const int maxn = 10;
const int maxq = 20;

const int maxv = 10;

int main() {
    srand(time(nullptr));
    dim = rand() % 4 + 2;
    int n = rand() % maxn + 1;
    int q = rand() % maxq + 1;

    std::default_random_engine e(time(nullptr));
    std::uniform_int_distribution<int> u(-maxv, maxv);

    printf("%d %d\n", dim, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < dim; ++j) {
            printf("%d ", u(e));
        }
        printf("\n");
    }
    printf("%d\n", q);
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < dim; ++j) {
            printf("%d ", u(e));
        }
        printf("\n");
    }

    return 0;
}