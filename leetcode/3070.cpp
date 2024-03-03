/*
 * Leetcode Medium 3070. Count Submatrices with Top-Left Element and Sum Less Than k
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
    int dp[1001][1001];
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i-1][j-1];
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dp[i][j] <= k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}