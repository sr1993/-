/*
魔法王国一共有n个城市,编号为0~n-1号,n个城市之间的道路连接起来恰好构成一棵树。
小易现在在0号城市,每次行动小易会从当前所在的城市走到与其相邻的一个城市,小易最多能行动L次。
如果小易到达过某个城市就视为小易游历过这个城市了,小易现在要制定好的旅游计划使他能游历最多的城市,请你帮他计算一下他最多能游历过多少个城市(注意0号城市已经游历了,游历过的城市不重复计算)。
输入描述:

输入包括两行,第一行包括两个正整数n(2 ≤ n ≤ 50)和L(1 ≤ L ≤ 100),表示城市个数和小易能行动的次数。
第二行包括n-1个整数parent[i](0 ≤ parent[i] ≤ i), 对于每个合法的i(0 ≤ i ≤ n - 2),在(i+1)号城市和parent[i]间有一条道路连接。


输出描述:

输出一个整数,表示小易最多能游历的城市数量。
示例1
输入

5 2
0 1 2 3
输出

3

解题思路：
给定的是一个树，而且根据(0 ≤ parent[i] ≤ i)条件可知，题目给出的边都是从小编号指向大编号，因此可以建立一个单向图，把编号0的节点作为根节点。
然后用DFS从根节点遍历，找到最长的一个链（根节点到叶子节点长度最长的，也就是走的步数最多的），设走这个链的步数为maxLen.
题目给定最多可以走的步数为L
1. 如果maxLen >= L, 意思是最长的链走不完，此时的答案是L+1, 1是根节点代表的城市
2. 如果maxLen < L, 那么剩余的步数是 L - maxLen， 此时可以用剩下的步数去走其它的节点，注意到只要多走一个节点就要消耗2个步数
比如  0 -> 2 -> 4 -> 8是最长的链，然后假设2那里有分支，假设2 - > 3 - > 5 如果要拿剩余的步骤去走这个链的分支，如果走到3，多访问1个节点，需要消耗2步，因为是来回，
如果走到5，多访问两个节点，来回需要消耗4步。因此可以得出结论，剩余的步数假设是left, 那么剩余的步数可以访问的节点个数为 left / 2, 此时答案是
min(n, maxLen + 1 + left/2) ，需要min,因为L可能太大，可以把所有节点访问完，而且还有剩余步数。


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

       //目前走了maxLen步，也就是游览了maxLen+1这么多城市
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
