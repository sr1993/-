/*
一个合法的括号匹配序列被定义为:
1. 空串""是合法的括号序列
2. 如果"X"和"Y"是合法的序列,那么"XY"也是一个合法的括号序列
3. 如果"X"是一个合法的序列,那么"(X)"也是一个合法的括号序列
4. 每个合法的括号序列都可以由上面的规则生成
例如"", "()", "()()()", "(()())", "(((()))"都是合法的。
从一个字符串S中移除零个或者多个字符得到的序列称为S的子序列。
例如"abcde"的子序列有"abe","","abcde"等。
定义LCS(S,T)为字符串S和字符串T最长公共子序列的长度,即一个最长的序列W既是S的子序列也是T的子序列的长度。
小易给出一个合法的括号匹配序列s,小易希望你能找出具有以下特征的括号序列t:
1、t跟s不同,但是长度相同
2、t也是一个合法的括号匹配序列
3、LCS(s, t)是满足上述两个条件的t中最大的
因为这样的t可能存在多个,小易需要你计算出满足条件的t有多少个。

如样例所示: s = "(())()",跟字符串s长度相同的合法括号匹配序列有:
"()(())", "((()))", "()()()", "(()())",其中LCS( "(())()", "()(())" )为4,其他三个都为5,所以输出3.
输入描述:

输入包括字符串s(4 ≤ |s| ≤ 50,|s|表示字符串长度),保证s是一个合法的括号匹配序列。


输出描述:

输出一个正整数,满足条件的t的个数。
示例1
输入

(())()
输出

3

解题思路：
关键点：如果字符串s, t的长度是len的话，那么LCS(s,t)的最长公共子序列一定是 len - 1
题目中长度大等于4，当时4的时候:
1. ()()这种情况，此时可以移动第三个字符，变成(())
2. (())这种情况，此时可以移动第三个字符，变成()()
因此只要将第k个位置的字符(1<=k<=len-2)移动到一个位置，这里所说的位置都不包括左右两端，左右两端都是固定的,
就可能得到一个符号要求的t，此时LCS(s,t) = len -1
因此，解法就是枚举每个位置的字符，然后将该字符插入到某个位置，得到一个新的字符串，判断这个新的字符串是否合法，
如果合法，就是一种答案。
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

bool isok(string str)
{
    int cntL = 0;//左括号
    int cntR = 0;//右括号
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
            cntL++;
        else
            cntR++;
        if(cntR > cntL)
            return false;
    }
    return true;
}

set<string> ans;

int main()
{
    string ori;//原始串
    while(cin >> ori)
    {
        ans.clear();
        //遍历出去头尾两个其它的位置
        for(int i = 1; i < ori.length() - 1; i++)
        {
            //删除以后成了tp1
            string tp1(ori);
            tp1.erase(i, 1);
            //插入到其它位置
            for(int j = 1; j < tp1.length(); j++)
            {
                string tp2(tp1);
                tp2.insert(j, 1, ori[i]);
                if(isok(tp2) && tp2 != ori)
                    ans.insert(tp2);
            }
        }
        cout << ans.size() << endl;
    }
    return 0;
}
