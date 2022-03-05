/*
 *  C - 1111gal password
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "C"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front

#define N 1000000
#define MOD 998244353
int n;
int dp[N+5][10]; // [total_digit][number] = how many

void build()
{
    for(int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            if(j != 9)
            {
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
            if(j != 1)
            {
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;
            }

            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
}

int main()
{
    build();

    // for(int i = 1; i <= 3; i++)
    // {
    //     printf("D=%d\n", i);
    //     for(int j = 1; j <= 9; j++)
    //         printf("%d%c", dp[i][j], j == 9 ? '\n' : ' ');
    // }

    while(cin >> n)
    {
        int ans = 0;
        for(int i = 1; i <= 9; i++)
        {
            ans += dp[n][i];
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
}