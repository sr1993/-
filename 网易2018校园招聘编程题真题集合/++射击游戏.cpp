/*
小易正在玩一款新出的射击游戏,这个射击游戏在一个二维平面进行,小易在坐标原点(0,0),平面上有n只怪物,每个怪物有所在的坐标(x[i], y[i])。小易进行一次射击会把x轴和y轴上(包含坐标原点)的怪物一次性消灭。
小易是这个游戏的VIP玩家,他拥有两项特权操作:
1、让平面内的所有怪物同时向任意同一方向移动任意同一距离
2、让平面内的所有怪物同时对于小易(0,0)旋转任意同一角度
小易要进行一次射击。小易在进行射击前,可以使用这两项特权操作任意次。
小易想知道在他射击的时候最多可以同时消灭多少只怪物,请你帮帮小易。

如样例所示:

图片地址：https://uploadfiles.nowcoder.com/images/20170908/906271_1504858526319_5919175DAEBEFEF2DD7B449C60B277DF
所有点对于坐标原点(0,0)顺时针或者逆时针旋转45°,可以让所有点都在坐标轴上,所以5个怪物都可以消灭。

输入描述:

输入包括三行。
第一行中有一个正整数n(1 ≤ n ≤ 50),表示平面内的怪物数量。
第二行包括n个整数x[i](-1,000,000 ≤ x[i] ≤ 1,000,000),表示每只怪物所在坐标的横坐标,以空格分割。
第二行包括n个整数y[i](-1,000,000 ≤ y[i] ≤ 1,000,000),表示每只怪物所在坐标的纵坐标,以空格分割。


输出描述:

输出一个整数表示小易最多能消灭多少只怪物。
示例1
输入

5
0 -1 1 1 -1
0 -1 -1 1 1
输出

5

解题思路：
最关键的思维就是 想象在坐标中建立一个又一个十字直线，那么无论这个十字直线相对于点所在的坐标系是什么角度或者位置，
该十字直线总可以通过平移或者旋转角度和点所在的坐标系重合，也就是说原来十字直线上存在的点都可以被消灭掉。

所以，就去枚举这个十字直线。
4个for循环，第一个是代表枚举的第一个点，第二个for是枚举的第二个点，这两个点组成一条直线,这样
十字直线就确定了一条直线，第三个for枚举第三个点，保证这三个点是不同的三个点，且第三个点不在前两个点的直线上，那么
通过第三个点做前面两个点所在直线的垂线，这样就得到了两条相互垂直的直线。第四个for循环，代表剩下的点，看剩下的点
是否在这两条直线上，如果在的话，就可以一块被消灭。

设4个点，A ,B ,C ,D，坐标分别为(Ax, Ay) (Bx, By) (Cx, Cy) (Dx, Dy)
判断点C是否在A B组成的直线上，用斜率计算，直线AB的斜率为 (Ay-By)/ (Ax - BX) AC的斜率是 (Ay-Cy) / (Ax - Cx)
如果共线则他们的斜率相等，为了避免除以0的情况，就直接判断是否  (Ay-By) * (Ax - Cx) == (Ax - BX) * (Ay-Cy)

判断CD是否与AB垂直的话，用它们的斜率相乘等于-1来判断。

另外需要注意的一点是：如果题目中给定的n个点都在同一条直线上，那么用上面的方法是无效的，因此如果发现用上面的方法
算不出答案，也就是第三个for循环怎么枚举都不满足条件，就说明n个点都在同一条直线，该直线可以平移旋转与坐标轴重合，
答案为n。
*/


#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
#define rd(x) scanf("%d", &x)
#define rd2(x, y) scanf("%d%d", &x,&y)
#define rdL2(x, y) scanf("%lld%lld", &x, &y)
#define rdL3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define LL long long
#include <set>
const int maxn = 52;
int x[maxn];
int y[maxn];
int dx[maxn][maxn];//任意两个点的x差值
int dy[maxn][maxn];//任意两个点的y差值
int n;

int main()
{
    while(rd(n) != EOF)
    {
        for(int i = 0; i < n; i++)
            rd(x[i]);
        for(int i = 0; i < n; i++)
            rd(y[i]);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dx[i][j] = x[i] - x[j];
                dy[i][j] = y[i] - y[j];
            }
        }
        int ans = -1;
        //第一个点
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(k == i || k == j)//不同点
                        continue;
                    if(dx[i][j] * dy[i][k] == dx[i][k] * dy[i][j])
                        continue;
                    int cnt = 3;//上面三个不同的点
                    for(int p = 0; p < n; p++)
                    {
                       if(p == i || p == j || p == k)
                            continue;
                       if(dx[i][j] * dy[i][p] == dx[i][p] * dy[i][j]
                          || dx[i][j] * dx[k][p] == -dy[i][j] * dy[k][p])
                        cnt++;
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        if(ans == -1)//所有的点都共线
            ans = n;
        cout << ans<<endl;
    }
    return 0;
}
