/*
 * Leetcode Medium 2212. Maximum Points in an Archery Competition
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

#define N 12
#define M 100000
// weight, value
int w[N+5], v[N+5];
int dp[N+1][M+1];
class Solution
{
public:
    void solve(int n, int m)
    {
        for(int i = 1; i <= n; i++) // item
        {
            for(int j = 0; j <= m; j++) // volume
            {
                dp[i][j] = dp[i-1][j];
                if(j >= w[i])
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    vector<int> maximumBobPoints(int n, vector<int>& a)
    {
        // vector<int> b(13);
        int b[15] = {};

        for(int i = 1; i <= N; i++)
        {
            v[i] = i-1;
            w[i] = a[i-1] + 1;
        }

        solve(12, n);

        // trace path
        for(int i = 12, j = n; i >= 1; i--)
        {
            // picked item i
            if(dp[i][j] != dp[i-1][j])
            {
                b[i] = w[i];
                j -= w[i];
            }

            if(i == 1 && j > 0)
                b[1] += j;
        }

        return vector(b+1, b+N+1);
    }
};

int main()
{
    // int n = 9;
    // vector<int> a = {1,1,0,1,0,0,2,1,0,1,2,0};
    int n = 89;
    vector<int> a = {3,2,28,1,7,1,16,7,3,13,3,5};
    auto x = Solution{}.maximumBobPoints(n, a);
    DBG(x);
}