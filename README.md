# 数据结构 2024秋

#### 授课教师：陈键飞

虽然是陈键飞老师的课堂，但实际上DSA现在三个课堂已经完全是平行课堂了，作业考试都没有任何区别。

由于DSA课程组的要求，本仓库**不公开源代码和报告**，仅保留2024秋部分题目的**可执行文件**和**对拍代码**，供对拍使用。

目前仓库中包含的题目有

|题目|考点|
|:---|:---|
|LAB1 Embrace DSA|测试和调试|
|LAB2 Zuma|代码测试和测例构造|
|LAB3 HashFun|哈希表|
|LAB4-1 BBST|平衡二叉搜索树|
|PA1-1-2 Interview|双向链表|
|PA1-2-2 Graphics|排序，二分查找|
|PA2-1-3 Stock|优先队列|
|PA2-2-2 Polynomial|栈|
|PA2-3-2 Build(hard)|二叉树/多叉树|
|PA3-1-3 Feature|BBST|
|PA3-2-2 Kidd|线段树|
|PA3-3-3 Nearest Neighbor|KD树|
|PA4-1-2 Game|Dijstra最短路算法|
|PA4-2-3 Pattern Matching|哈希策略，KMP|
|PA4-3-2 Component|左式堆，并查集|

每道题目的文件夹中，往往含有以下类型的文件：

- 可执行文件，分为Windows的版本（code.exe）和Linux的版本（code）；
- 随机数据生成器，一般为`data.cpp`，可以生成一组符合题目要求的随机输入数据，可在代码中全局变量部分调整生成参数（个别题目数据生成器可能并不完善，如Game就未考虑图的连通性，不适用于大批量自动化测试）；
- 对拍代码，一般为`battle.cpp`，可以调用数据生成器生成一组数据，再分别对比`code.cpp`（认为是自己的代码）和`reference.cpp`（认为是对拍代码）两份代码的输出，实际使用时由于未提供对拍源代码，可以删去编译部分；
- 自动化测试代码，一般为`automation.cpp`或`automation.py`，可以连续多次（次数在`automation`代码中设置）生成随机输入并对比两份代码的输出，遇到输出不一致的情况会自动停止，便于找到使代码WA/RE的测例。
- 时间测试代码，一般为`test.cpp`或`test.py`，一般用于单独测试一份代码（输出是否为空、运行时间等）。

以上提到的测试用代码，Windows上可能无法运行，建议在Linux上运行。

并非每个题目文件夹中都含有以上提到的所有测试代码，但测试代码在题目之间是通用的，完全可以迁移使用。

附课程组对于查重处理的规定：
Honor Code 要求客观、准确、完整，代码雷同判罚时**不区分双方角色**。例子：
- 甲声明参考了 github.com/yy/zz ，代码核心部分出现雷同，雷同部分与该链接相符
黑盒白盒置为 0 分
- 甲声明参考了 github.com/yy/zz ，代码核心部分出现雷同，雷同部分与该链接不符
黑盒白盒置为 -100 分
- 甲声明参考了 GitHub，没有指明具体链接，代码核心部分出现雷同
黑盒白盒置为 -100 分
- 甲声明参考了 github.com/yy/zz ，代码非核心部分出现雷同，雷同部分与该链接相符
黑盒分数八折（具体数值视情况而定）
- 甲声明本题参考了乙，乙未声明。判为代码雷同后，双方都声称甲是参考方，乙是被参考方，且代码提交时间甲在乙之后
甲置为 0 分，乙置为 -100 分
