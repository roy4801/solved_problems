/*
 * Leetcode Medium 62. Unique Paths
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define arr array
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == 1 && j == 1)
                    continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};

int main()
{
    using InputType=pair<int,int>;
    vector<InputType> in = {
        {3, 7},
        {3, 2},
        {100, 100},
    };
    for(auto &i : in)
        DBG(Solution{}.uniquePaths(i.X, i.Y));
}