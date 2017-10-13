/*
小易有一个长度为N的正整数数列A = {A[1], A[2], A[3]..., A[N]}。
牛博士给小易出了一个难题:
对数列A进行重新排列,使数列A满足所有的A[i] * A[i + 1](1 ≤ i ≤ N - 1)都是4的倍数。
小易现在需要判断一个数列是否可以重排之后满足牛博士的要求。
输入描述:

输入的第一行为数列的个数t(1 ≤ t ≤ 10),
接下来每两行描述一个数列A,第一行为数列长度n(1 ≤ n ≤ 10^5)
第二行为n个正整数A[i](1 ≤ A[i] ≤ 10^9)


输出描述:

对于每个数列输出一行表示是否可以满足牛博士要求,如果可以输出Yes,否则输出No。
示例1
输入

2
3
1 10 100
4
1 2 3 4
输出

Yes
No

解题思路：
奇数的左右两边必须是4，不能是两个2，因为 2 2 3 这样 2 3相乘不能被4整除。
把4的倍数的数就叫做4,2的倍数的数叫做2，其它的奇数叫做1.
最关键的一个点就是如果有多个2的倍数的数，一定要把他们连起来放在一块。因为如果一个单独的2，那么它左边必须有4， 右边也必须有4，两端除外，此时是对4的一个浪费。
比如 222441,如果把一个2单独拎出来，那么它消耗的4个个数最少是1，此时2在第一个数或者最后一个数，而其他的两个2还会最少消耗一个4，这样就最少消耗了两个4，
而如果把222连起来，那么最少消耗4的个数是1，因此如果有多个2，一定要把它们连起来。

设cnt1 为奇数的个数， cnt2是2的倍数的个数， cnt4是4的倍数的个数
1. 如果 cnt2 == 0的话， 1 4 1 4 1 ，满足的条件是 cnt4 >= cnt1 - 1,把4放在两个奇数中间
2. 如果cnt2 不等于0 ， 1 4 2 2 4 1，满足的条件是 cnt4 >= cnt1， 可以把连续的几个2看做是一个奇数
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
int t, n;
int cnt1, cnt2, cnt4;


int main()
{
    rd(t);
    while(t --)
    {
        cnt1 = 0; cnt2 = 0; cnt4 = 0;
        rd(n);
        int x;
        while(n--)
        {
            rd(x);
            if(x % 4 == 0)
                cnt4++;
            else if(x % 2 == 0)
                cnt2++;
            else
                cnt1++;
        }
        if(cnt4 >= cnt1 ||(cnt4 >= cnt1 - 1 && cnt2 ==0))
        {
            cout << "Yes" <<endl;
        }
        else
        {
            cout << "No" << endl;
        }

    }
    return 0;
}
