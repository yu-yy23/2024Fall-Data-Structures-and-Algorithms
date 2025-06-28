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

    std::uniform_int_distribution<int> MM(1, maxM);
    std::uniform_int_distribution<int> NN(1, maxN);
    std::uniform_int_distribution<int> mm(1, maxm);
    std::uniform_int_distribution<int> nn(1, maxn);
    std::uniform_int_distribution<int> kk(1, maxk);

    //int M = MM(e), N = NN(e), m = mm(e), n = nn(e), k = kk(e);
    int M = 50, N = 50, m = 10, n = 10, k = 10;

    printf("%d %d %d %d %d\n", M, N, m, n, k);

    //char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //std::uniform_int_distribution<int> p(0, 51);
    char chars[] = "ab";
    std::uniform_int_distribution<int> p(0, 1);

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%c", chars[p(e)]);
        }
        printf("\n");
    }

    for (int l = 0; l < k; ++l) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("%c", chars[p(e)]);
            }
            printf("\n");
        }
    }

    return 0;
}