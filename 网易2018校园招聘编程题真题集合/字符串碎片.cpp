/*
һ����Сд��ĸ��ɵ��ַ������Կ���һЩͬһ��ĸ�������Ƭ��ɵġ�����,"aaabbaaac"����������Ƭ��ɵ�:'aaa','bb','c'��ţţ���ڸ���һ���ַ���,���������������ַ�����������Ƭ��ƽ�������Ƕ��١�

��������:

�������һ���ַ���s,�ַ���s�ĳ���length(1 �� length �� 50),sֻ��Сд��ĸ('a'-'z')


�������:

���һ������,��ʾ������Ƭ��ƽ������,�������뱣����λС����

��������ʾ: s = "aaabbaaac"
������Ƭ��ƽ������ = (3 + 2 + 3 + 1) / 4 = 2.25
ʾ��1
����

aaabbaaac
���

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
