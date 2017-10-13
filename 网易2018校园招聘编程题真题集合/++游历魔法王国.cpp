/*
ħ������һ����n������,���Ϊ0~n-1��,n������֮��ĵ�·��������ǡ�ù���һ������
С��������0�ų���,ÿ���ж�С�׻�ӵ�ǰ���ڵĳ����ߵ��������ڵ�һ������,С��������ж�L�Ρ�
���С�׵����ĳ�����о���ΪС�����������������,С������Ҫ�ƶ��õ����μƻ�ʹ�����������ĳ���,�����������һ������������������ٸ�����(ע��0�ų����Ѿ�������,�������ĳ��в��ظ�����)��
��������:

�����������,��һ�а�������������n(2 �� n �� 50)��L(1 �� L �� 100),��ʾ���и�����С�����ж��Ĵ�����
�ڶ��а���n-1������parent[i](0 �� parent[i] �� i), ����ÿ���Ϸ���i(0 �� i �� n - 2),��(i+1)�ų��к�parent[i]����һ����·���ӡ�


�������:

���һ������,��ʾС������������ĳ���������
ʾ��1
����

5 2
0 1 2 3
���

3

����˼·��
��������һ���������Ҹ���(0 �� parent[i] �� i)������֪����Ŀ�����ı߶��Ǵ�С���ָ����ţ���˿��Խ���һ������ͼ���ѱ��0�Ľڵ���Ϊ���ڵ㡣
Ȼ����DFS�Ӹ��ڵ�������ҵ����һ���������ڵ㵽Ҷ�ӽڵ㳤����ģ�Ҳ�����ߵĲ������ģ�������������Ĳ���ΪmaxLen.
��Ŀ�����������ߵĲ���ΪL
1. ���maxLen >= L, ��˼��������߲��꣬��ʱ�Ĵ���L+1, 1�Ǹ��ڵ����ĳ���
2. ���maxLen < L, ��ôʣ��Ĳ����� L - maxLen�� ��ʱ������ʣ�µĲ���ȥ�������Ľڵ㣬ע�⵽ֻҪ����һ���ڵ��Ҫ����2������
����  0 -> 2 -> 4 -> 8���������Ȼ�����2�����з�֧������2 - > 3 - > 5 ���Ҫ��ʣ��Ĳ���ȥ��������ķ�֧������ߵ�3�������1���ڵ㣬��Ҫ����2������Ϊ�����أ�
����ߵ�5������������ڵ㣬������Ҫ����4������˿��Եó����ۣ�ʣ��Ĳ���������left, ��ôʣ��Ĳ������Է��ʵĽڵ����Ϊ left / 2, ��ʱ����
min(n, maxLen + 1 + left/2) ����Ҫmin,��ΪL����̫�󣬿��԰����нڵ�����꣬���һ���ʣ�ಽ����


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

const int maxn = 60;
int n, L;
map<int, vector<int> > edges;
int maxLen = 0;




void dfs(int to, int depth)
{
    maxLen = max(maxLen, depth);
    for(int i = 0; i < edges[to].size(); i++)
    {
        dfs(edges[to][i], depth + 1);
    }
}



int main()
{
    while(rd2(n, L) != EOF)
    {
       edges.clear();
       int from;
       for(int i = 0; i <= n - 2; i++)
       {
           rd(from);
           edges[from].push_back(i + 1);
       }

       maxLen = -1;

       for(int i = 0; i < edges[0].size(); i++)
       {
           dfs(edges[0][i], 1);
       }

       //Ŀǰ����maxLen����Ҳ����������maxLen+1��ô�����
       if(L <= maxLen)
       {
           cout << L + 1 <<endl;
       }
       else
       {
           int left = L - maxLen;
           cout << min(n, (left / 2 + maxLen + 1)) << endl;
       }

    }
    return 0;
}
