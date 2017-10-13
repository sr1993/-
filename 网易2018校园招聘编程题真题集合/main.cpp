#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <map>
using namespace std;
#define rd(x) scanf("%d", &x)
#define rd2(x, y) scanf("%d%d", &x, &y)
#define rd3(x, y, z) scanf("%d%d%d", &x, &y, &z)
const int maxn = 210;



int matrix[maxn][maxn];
multiset<int> mulSet;
int total[maxn][maxn]; //把上一行的数都加上下一行上去
int N;
int K, A1, B1, C, D, E1, E2, F;
long long A[maxn], B[maxn];
long long x[maxn], y[maxn];
long long r[maxn], s[maxn];

void init()
{
    A[1] = A1;
    B[1] = B1;
    x[1] = A1;
    y[1] = B1;
    r[1] = 0;
    s[1] = 0;
    memset(total, 0, sizeof(total));
    memset(matrix, 0, sizeof(matrix));
    mulSet.clear();
}

void calXiYiRiSiAiBiAndMatics()
{
    for(int i = 2; i <= N; i++)
    {
        x[i] = (C * x[i - 1] + D * y[i - 1] + E1) % F;
        y[i] = (D * x[i - 1] + C * y[i - 1] + E2) % F;
        r[i] = (C * r[i - 1] + D * s[i - 1] + E1) % 2;
        s[i] = (D * r[i - 1] + C * s[i - 1] + E2) % 2;
        A[i] = ((r[i] & 1) ? (-1) : 1) * x[i];
        B[i] = ((s[i] & 1) ? (-1) : 1) * y[i];
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            matrix[i][j] = A[i] * B[j];
        }
    }

}

void getTotal()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            total[i][j] = total[i - 1][j] + matrix[i][j];
        }
    }
}

int maxSumOfSubSequence(int* num, int len)
{
    int maxSum = -0x7f7f7f7f;
    int tpSum = 0;
    for(int i = 1; i <= len; i++)
    {
        tpSum += num[i];
        if(tpSum > maxSum)
        {
            maxSum = tpSum;
            mulSet.insert(maxSum);
        }
        if(tpSum < 0)
        {
            tpSum = 0;
        }
    }
    return maxSum;
}


int main()
{
    int T;
    rd(T);
    for(int cas = 1; cas <= T; cas ++)
    {
        rd3(N, K, A1);
        rd3(B1, C, D);
        rd3(E1, E2, F);

        init();
        calXiYiRiSiAiBiAndMatics();
        getTotal();
/*
        for(int i = 1;i <= N; i++)
        {
            for(int j = 1; j<= N; j++)
            {
                cout << matrix[i][j] <<" ";
            }
            cout << endl;
        }
        cout << endl;

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1;j <= N; j++)
            {
                cout << total[i][j] <<" ";
            }
            cout << endl;
        }
*/
        //每次挑两行
        for(int i = 1; i <= N; i++)
        {
            for(int j = i; j <= N; j++)
            {
                int sum[maxn];
                for(int col = 1; col <= N; col ++)
                {
                    sum[col] = total[j][col] - total[i - 1][col];
                    //cout <<" sum:  " << sum[col] <<"  ";
                }
                cout << endl;
                int maxSumOfSub = maxSumOfSubSequence(sum, N);
                cout <<" maxSumOfSum    : " <<maxSumOfSub<<endl;
               /* if(mulSet.size() < K)
                    mulSet.insert(maxSumOfSub);
                else
                {
                    mulSet.insert(maxSumOfSub);
                    mulSet.erase(mulSet.begin());
                }
                */
                while(mulSet.size() > K)
                {
                    mulSet.erase(mulSet.begin());
                }
            }
        }
        cout <<"size   "<<mulSet.size()<<endl;
        int ans = *(mulSet.begin());
        cout <<"Case #" << cas << ": " << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
   // system("out.txt");
    return 0;
}
