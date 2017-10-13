/*
链接：https://www.nowcoder.com/questionTerminal/ef6262d0381d42ebbe22d8a8554fef01
来源：牛客网

为了得到一个数的"相反数",我们将这个数的数字顺序颠倒,然后再加上原先的数得到"相反数"。例如,为了得到1325的"相反数",首先我们将该数的数字顺序颠倒,我们得到5231,之后再加上原先的数,我们得到5231+1325=6556.如果颠倒之后的数字有前缀零,前缀零将会被忽略。例如n = 100, 颠倒之后是1.
输入描述:

输入包括一个整数n,(1 ≤ n ≤ 10^5)


输出描述:

输出一个整数,表示n的相反数
示例1
输入

1325
输出

6556
*/
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;
#define rd(x) scanf("%d", &x)
#define rdL2(x, y) scanf("%lld%lld", &x, &y)
#define rdL3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define LL long long
int n;

int re(int n)
{
    int ans = 0;
    while(n)
    {
        ans = ans * 10 + (n % 10);
        n /= 10;
    }
    return ans;
}

int main()
{
   while(rd(n) != EOF)
   {
       cout << re(n) + n << endl;
   }
    return 0;
}
