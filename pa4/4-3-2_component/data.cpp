#include <cstdio>
#include <random>
#include <ctime>

const int maxn = 1e6;
const int maxm = 1e6;
const int maxk = 1e6;
const int maxq = 1e6;

const int maxv = 1e9;

int main() {
    std::default_random_engine e(time(nullptr));
    std::uniform_int_distribution<int> nn(1, maxn);
    std::uniform_int_distribution<int> mm(1, maxm);
    std::uniform_int_distribution<int> kk(1, maxk);
    std::uniform_int_distribution<int> qq(1, maxq);
    int n = nn(e);
    int m = mm(e);
    int k = kk(e);
    int q = qq(e);
    // int n = 1e6;
    // int m = 1e6;
    // int k = 1e6;
    // int q = 1e6;
    printf("%d %d %d %d\n", n, m, k, q);

    std::uniform_int_distribution<int> v(0, maxv);
    std::uniform_int_distribution<int> u(1, n);
    std::uniform_int_distribution<int> o(1, 2);

    for (int i = 0; i < n; ++i) {
        printf("%d ", v(e));
    }
    printf("\n");

    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", u(e), u(e));
    }

    for (int i = 0; i < q; ++i) {
        int op = o(e);
        printf("%d ", op);
        if (op == 1) {
            printf("%d %d\n", u(e), u(e));
        } else {
            printf("%d\n", u(e));
        }
    }

    return 0;
}