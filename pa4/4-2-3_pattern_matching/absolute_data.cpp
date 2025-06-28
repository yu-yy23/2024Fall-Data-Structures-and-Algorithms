#include <cstdio>
#include <random>
#include <ctime>

const int maxM = 2000;
const int maxN = 1000;
const int maxm = 10;
const int maxn = 10;
const int maxk = 100;

int main() {
    std::default_random_engine e(time(nullptr));

    int M = maxM, N = maxN, m = maxm, n = maxn, k = maxk;

    printf("%d %d %d %d %d\n", M, N, m, n, k);

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%c", 'a');
        }
        printf("\n");
    }

    for (int l = 0; l < k; ++l) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("%c", 'a');
            }
            printf("\n");
        }
    }

    return 0;
}