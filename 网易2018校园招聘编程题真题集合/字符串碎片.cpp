/*
一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。例如,"aaabbaaac"是由下面碎片组成的:'aaa','bb','c'。牛牛现在给定一个字符串,请你帮助计算这个字符串的所有碎片的平均长度是多少。

输入描述:

输入包括一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),s只含小写字母('a'-'z')


输出描述:

输出一个整数,表示所有碎片的平均长度,四舍五入保留两位小数。

如样例所示: s = "aaabbaaac"
所有碎片的平均长度 = (3 + 2 + 3 + 1) / 4 = 2.25
示例1
输入

aaabbaaac
输出

2.25
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
#define rdL2(x, y) scanf("%lld%lld", &x, &y)
#define rdL3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define LL long long
#include <set>

int n;
string str;
vector<string> strs;

void process(string str)
{
    strs.clear();
    string part = "";
    for(int i = 0; i < str.length(); i++)
    {
        if(i == 0)
        {
            part += str[i];
        }
        else
        {
            if(str[i] == str[i - 1])
            {
                part += str[i];
                if(i == str.length() - 1)
                {
                    strs.push_back(part);
                    part = "";
                }
            }
            else
            {
                strs.push_back(part);
                part = "";
                part += str[i];
                if(i == str.length() - 1)
                {
                    strs.push_back(part);
                }
            }
        }

    }
}

int main()
{
    while(cin >> str)
    {
        process(str);
        vector<string>::iterator  it;
        int totalLen = 0;
        for(it = strs.begin(); it != strs.end(); it++)
        {
            totalLen += (*it).length();
        }
        double ans = 1.0 * totalLen / strs.size();
        printf("%.2f\n", ans);

    }
    return 0;
}
