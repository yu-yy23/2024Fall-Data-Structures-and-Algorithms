#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>

const int low = 1;
const int high = 1000000;
const unsigned int max = pow(2, 31);

int main() {
    srand(time(0));

    int n = rand() % (high - low) + low + 1;
    int m = 2 * n;

    std::set<int> s;
    while (s.size() < n) {
        s.insert(rand() % (m - 1));
    }
    
    printf("%d\n", n);
    for (int i = 0; i < m; ++i) {
        printf("%d ", rand() % 1000 + 1);
        if (s.find(i) != s.end()) {
            printf("%d\n", rand() % max);
        } else {
            printf("\n");
        }
    }

    return 0;
}