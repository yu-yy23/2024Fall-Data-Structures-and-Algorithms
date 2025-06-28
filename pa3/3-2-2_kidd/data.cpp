#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>

const long long int low = 1;
const long long int high = 2e31;
const unsigned int max = 256;

int main() {
    srand(time(0));

    int n = rand() % (high - low) + low + 1;
    int m = rand() % 200000 + 1;

    printf("%d %d\n", n, m);
    char op[2] = {'H', 'Q'};
    for (int i = 0; i < m; ++i) {
        int s = rand() % n + 1;
        int t = 0;
        while (t < s) t = rand() % n + 1;
        printf("%c %d %d\n", op[rand() % 2], s, t);
    }

    return 0;
}