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
    assert(argc <= 5);

    // 随机数生成器
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<int> nn(1, MAXN);

    int n = nn(e), mx = MAXX, percent = 50;     // 操作次数，数据极大值，插入操作百分比
    freopen("data.in", "w", stdout);            // 输出重定向

    // 读入参数
    if (argc >= 2) {
        n = atoi(argv[1]);
    }
    if (argc >= 3) {
        mx = atoi(argv[2]);
    }
    if (argc >= 4) {
        percent = atoi(argv[3]);
    }
    if (argc >= 5) {
        freopen(argv[4], "w", stdout);
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

    // 插入次数和查找次数
    int insert = n * percent / 100;
    int search = n - insert;

    // 生成插入操作
    for (int i = 0; i < insert; ++i) {
        char op = 'A';
        int x = xx(e);

        // 保证同一时刻不存在重复节点
        if (flag[x]) {
            --i;
            continue;
        } else {
            flag[x] = true;
        }

        printf("%c %d\n", op, x);
    }

    // 生成查找操作
    int x = xx(e);
    while (!flag[x]) {
        x = xx(e);
    }
    for (int i = 0; i < search; ++i) {
        char op = 'C';
        printf("%c %d\n", op, x);
    }

    delete[] flag;

    return 0;
}