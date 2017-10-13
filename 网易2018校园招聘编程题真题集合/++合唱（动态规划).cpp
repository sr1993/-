/*

小Q和牛博士合唱一首歌曲,这首歌曲由n个音调组成,每个音调由一个正整数表示。
对于每个音调要么由小Q演唱要么由牛博士演唱,对于一系列音调演唱的难度等于所有相邻音调变化幅度之和, 例如一个音调序列是8, 8, 13, 12, 那么它的难度等于|8 - 8| + |13 - 8| + |12 - 13| = 6(其中||表示绝对值)。
现在要对把这n个音调分配给小Q或牛博士,让他们演唱的难度之和最小,请你算算最小的难度和是多少。
如样例所示: 小Q选择演唱{5, 6}难度为1, 牛博士选择演唱{1, 2, 1}难度为2,难度之和为3,这一个是最小难度和的方案了。
输入描述:

输入包括两行,第一行一个正整数n(1 ≤ n ≤ 2000) 第二行n个整数v[i](1 ≤ v[i] ≤ 10^6), 表示每个音调。


输出描述:

输出一个整数,表示小Q和牛博士演唱最小的难度和是多少。
示例1
输入

5
1 5 6 2 1
输出

3

动态规划的题目，好难。这种题目最难的地方就是如何用数组表示状态，要保存什么样的状态，也就是dp数组该怎么设计，
然后状态之间的转移应该是怎么样的。如果把这些问题搞清楚了，才能去写代码。
dp[i][j] 表示第一个人最近唱的是第i个字符，第二个人最近唱的是第j个字符，保证i是大于j的，也就是字符从左到右，第一个人唱的总比第二个人靠后。
其实第一个人也可以当做是第二个人，第二个人也可以当做第一个人，因此有dp[i][j] = dp[j][i]。

为了方便，先把dp数据的边界处理好，n < 3，答案是0。然后处理好dp[0][1] dp[1][0] dp[2][1] dp[1][2] dp[0][2] dp[2][0]这样的边界值。
第一个for循环，枚举第一个人唱音符的位置，从3开始。此时可以计算出dp[i][i - 1],意思是第一个人唱第i个音符，前面0到i-1个音符都是从第二个人唱

然后考虑第一个人唱的是第i个音符，那么第i-1个音符是谁唱的：
1. 第 i - 1个音符也是第一个人唱的，那么dp[i][j] = dp[i - 1] + abs(v[i]- v[i-1]);
2. 第 i - 1个音符是第二个人唱的，那么上一次第一个人唱的音符位置假设是j, 0 <= j < i - 1，枚举j,有dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + abs(v[i] - v[j]))

最后dp[n - 1][i]  0 <= i < n - 1中的最小值为答案。

*/



#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
#define rd(x) scanf("%d", &x)
#define rd2(x, y) scanf("%d%d", &x,&y)
#define rdL2(x, y) scanf("%lld%lld", &x, &y)
#define rdL3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define LL long long
#include <set>

const int maxn = 2010;
int dp[maxn][maxn];//dp[i][j]前一个人唱第i个音符，后一个唱第j个音符，且假设i始终大于j，没有顺序问题，dp[i][j] = dp[j][i]
int v[maxn];//每个音符的难度
int sumAbs[maxn];
int n;

int main()
{
    while(rd(n) != EOF)
    {
        for(int i = 0; i < n; i++)
            rd(v[i]);

        if(n < 3)
        {
            cout << 0 << endl;
            continue;
        }

        memset(dp, -1, sizeof(dp));
        memset(sumAbs, 0, sizeof(sumAbs));
        //初始化一些值
        dp[0][1] = dp[1][0] = 0;
        dp[1][2] = dp[2][1] = abs(v[1] - v[0]);
        dp[0][2] = dp[2][0] = abs(v[2] - v[1]);
        sumAbs[0] = 0; sumAbs[1] = abs(v[1] - v[0]); sumAbs[2] = sumAbs[1] + abs(v[2] - v[1]);

        for(int i = 3; i < n ; i++)//第一个个人唱的是第i个音符
        {
            sumAbs[i] = sumAbs[i - 1] + abs(v[i] - v[i - 1]);
            //第一个人唱第i个音符，前面所有得的音符是第二个人唱
            dp[i][i - 1] = dp[i - 1][i] = sumAbs[i - 1];
            for(int j = 0; j < i - 1; j++)
            {
                //第i个音符不换人,也就是第一个人同时唱了第i个和第i-1个
                dp[i][j] = dp[i - 1][j] + abs(v[i] - v[i - 1]);
                dp[j][i] = dp[i][j];
                //第i个音符换人了，也就是第一个人唱第i个，第二个人唱了第i-1个，那么第一个人上一次最近的音符位置是j
                dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + abs(v[i] - v[j]));
                dp[i - 1][i] = dp[i][i - 1];
            }
        }
        int ans = 0x7fffffff;

        for(int i = 0; i < n - 1; i++)
        {
            if(ans > dp[n - 1][i])
                ans = dp[n - 1][i];
        }

        cout << ans << endl;

    }
    return 0;
}
