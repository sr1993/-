/*
���ӣ�https://www.nowcoder.com/questionTerminal/ef6262d0381d42ebbe22d8a8554fef01
��Դ��ţ����

Ϊ�˵õ�һ������"�෴��",���ǽ������������˳��ߵ�,Ȼ���ټ���ԭ�ȵ����õ�"�෴��"������,Ϊ�˵õ�1325��"�෴��",�������ǽ�����������˳��ߵ�,���ǵõ�5231,֮���ټ���ԭ�ȵ���,���ǵõ�5231+1325=6556.����ߵ�֮���������ǰ׺��,ǰ׺�㽫�ᱻ���ԡ�����n = 100, �ߵ�֮����1.
��������:

�������һ������n,(1 �� n �� 10^5)


�������:

���һ������,��ʾn���෴��
ʾ��1
����

1325
���

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
