# Doctorfleemap
## 图中各结点的概率计算问题

### 杀人狂魔汉尼拔博士逃狱了。通缉令发布后，大量军警出动并实施全天候追捕，不过狡猾的汉尼拔博士并没有落网。过了d日后，束手无策的警察们拜访了有着“编程天才”之称的查理教授。查理教授对汉尼拔博士留在监狱的笔记本进行分析后，做出了如下假设。
### 1）汉尼拔博士为了避开检查，只走山路；
### 2）汉尼拔博士越狱当天选择了与监狱相邻的村子之一作为藏身之处；
### 3）汉尼拔博士为了逃避追捕，每天往一个相邻的村子逃窜。
### 为了验证假设，教授找到了与监狱所在村子以山路连接的n个村子的地图。汉尼拔博士会按照此假设行动，而且会随机选择一个备选的村子。编写程序计算d日后汉尼拔博士在各个村子的概率。
### 例如监狱在第三个村子，逃狱后的汉尼拔博士会在0、1、2、4、5中任意选择一个村子藏身。因此，1天后汉尼拔博士藏在第0号村子的概率是1/5，两天后藏在第1号村子的概率是1/15。


输入
第一行输入测试用例的个数C（1≤C≤50）。之后各行输入地图上显示的村子个数N（2≤N≤50）和逃狱后经过的天数D（1≤D≤100），以及监狱所在村子的号码P（0≤P<N），村子的号码由0到N-1的数字组成。之后N行里各输入N个整数，形成一个序列A。第i行j列的数值A[i][j]如果等于1，就表示从第i号村子到第j号村子有山路可走；如果是0，则表示无路可通。接下来的一行输入要计算概率的村子的个数T（0≤T<N），最后一行以整数型输入要计算概率的村子的号码Q（0≤Q<N）。
如果一个村子与另一个村子相连，那么相反的路径也必定存在。可假设一个村子连接到自身的路径不存在。
输出
每个测试用例以T个实数输出汉尼拔博士可能藏匿的概率。存在小于10-7的绝对/相对误差的答案将被视为正确答案。
   示例输入值
2
5 2 0
0 1 1 1 0
1 0 0 0 1
1 0 0 0 0
1 0 0 0 0
0 1 0 0 0
3
0 2 4
8 2 3
0 1 1 1 0 0 0 0
1 0 0 1 0 0 0 0
1 0 0 1 0 0 0 0
1 1 1 0 1 1 0 0
0 0 0 1 0 0 1 1
0 0 0 1 0 0 0 1
0 0 0 0 1 0 0 0
0 0 0 0 1 1 0 0
4
3 1 2 6
示例输出值
0.83333333	0.00000000	0.16666667
0.43333333	0.06666667	0.06666667	0.06666667
