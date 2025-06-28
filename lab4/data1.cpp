#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cassert>

const int MAXN = 1000000;               // 最大节点数
const int MAXX = 8500000;               // 最大数据范围
const char ops[3] = {'A', 'B', 'C'};    // 操作类型
bool* flag;                             // 标记数据是否已存在

int main(int argc, char** argv) {
    assert(argc <= 4);

    // 随机数生成器
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<int> nn(1, MAXN);

    int n = nn(e), mx = MAXX;               // 操作次数，数据极大值
    freopen("data.in", "w", stdout);        // 输出重定向

    // 读入参数
    if (argc >= 2) {
        n = atoi(argv[1]);
    }
    if (argc >= 3) {
        mx = atoi(argv[2]);
    }
    if (argc >= 4) {
        freopen(argv[3], "w", stdout);
    }

    // 初始化标记数组
    flag = new bool[mx + 1];
    for (int i = 0; i < mx + 1; ++i) {
        flag[i] = false;
    }

    // 根据参数确定数据生成范围
    std::uniform_int_distribution<int> xx(0, mx);

    // 生成随机操作
    std::uniform_int_distribution<int> opp(0, 2);

    // 输出操作次数
    printf("%d\n", n);

    // 生成操作
    for (int i = 0; i < n; ++i) {
        char op = ops[opp(e)];
        int x = xx(e);

        // 保证同一时刻不存在重复节点
        if (op == 'A' && flag[x]) {
            --i;
            continue;
        } else if (op == 'A') {
            flag[x] = true;
        } else if (op == 'B') {
            flag[x] = false;
        }

        printf("%c %d\n", op, x);
    }

    delete[] flag;

    return 0;
}