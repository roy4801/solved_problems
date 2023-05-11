/*
 * Leetcode Medium 1035. Uncrossed Lines
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

#define N 500
class Solution {
public:
    int dp[N+5][N+5];
    int maxUncrossedLines(vector<int>& a, vector<int>& b)
    {
        int n = a.size(), m = b.size();
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};


int main()
{
    // skip
}