/*
С��׼��ȥħ�������ɹ�ħ������,����ħ��������Ҫʹ��ħ����,����С������һöħ���Ҷ�û��,����С������̨ħ����������ͨ��Ͷ��x(x����Ϊ0)��ħ���Ҳ��������ħ���ҡ�
ħ������1:���Ͷ��x��ħ����,ħ�������Ὣ���Ϊ2x+1��ħ����
ħ������2:���Ͷ��x��ħ����,ħ�������Ὣ���Ϊ2x+2��ħ����
С�ײɹ�ħ�������ܹ���Ҫn��ħ����,����С��ֻ��ͨ����̨ħ����������ǡ��n��ħ����,С����Ҫ��������һ��Ͷ�뷽��ʹ�����ǡ��ӵ��n��ħ���ҡ�
��������:

�������һ��,����һ��������n(1 �� n �� 10^9),��ʾС����Ҫ��ħ����������


�������:

���һ���ַ���,ÿ���ַ���ʾ�ô�С��ѡȡͶ���ħ������������ֻ�����ַ�'1'��'2'��
ʾ��1
����

10
���

122
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

int main()
{
    int n;
    while(rd(n) != EOF)
    {
        string ans = "";
        while(n)
        {
            if(n & 1)//������
            {
                n = (n - 1) / 2;
                ans += '1';
            }
            else
            {
                n = (n - 2) / 2;
                ans += '2';
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans <<endl;
    }
    return 0;
}
//�����û˵���ÿ�ο��Է�һ����Ǯ���Ǳ�������Ǯ��
