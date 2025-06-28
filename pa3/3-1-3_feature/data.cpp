#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <random>

bool flag[1000];
const int MAXN = 10;
const int MAXM = 10;
const int max = 100;

int weight[MAXN + 1];

int main() {
    srand(time(0));

    int w = 0, v = 0;
    bool sig = false;
    
    printf("%d %d\n", MAXN, MAXM);

    for (int i = 0; i < MAXN; i++) {
        do {
            w = rand() % max;
        } while (flag[w]);
        flag[w] = true;
        weight[i + 1] = w;

        sig = rand() % 2;
        if (sig) w = -w;

        v = rand() % max;
        printf("%d %d\n", w, v);
    }

    for (int i = 0; i < MAXM; i++) {
        int op = rand() % 3;
        if (op == 0) {
            int k = rand() % MAXN + 1;
            int x = rand() % max;
            printf("V %d %d\n", k, x);
        } else if (op == 1) {
            int k = rand() % MAXN + 1;
            printf("C %d\n", k);
        } else {
            int j = rand() % MAXN + 1;
            do {
                w = rand() % max;
            } while (flag[w]);
            flag[weight[j]] = false;
            flag[w] = true;
            weight[j] = w;
            printf("W %d %d\n", j, w);
        }
    }

    return 0;
}