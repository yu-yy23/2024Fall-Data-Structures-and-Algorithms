#include <cstdio>
#include <algorithm>

int main() {
    int n = 0;
    int x0 = 0, y0 = 0;
    scanf("%d", &n);
    int *x = new int[n];
    int *y = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &y[i]);
    }
    scanf("%d %d", &x0, &y0);

    std::sort(x, x + n);
    std::sort(y, y + n);

    for (int i = 0; i < n; ++i) {
        int left = x[i] * y0 + x0 * y[i];
        int right = x[i] * y[i];
        printf("%d/%d/%d\n", left, right, i + 1);
    }

    delete[] x;
    delete[] y;
    return 0;
}