/*
 * Leetcode Medium 931. Minimum Falling Path Sum
 * author: roy4801
 * AC(C++) 22ms
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

class Solution {
public:
    vector<vector<int>> M;
    int dp[105][105];
    int n, m;
    
    int solve(int i, int j)
    {
        if(j < 0 || j >= m)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == n-1)
            return M[i][j];

        int ans = solve(i+1, j-1);
        ans = min(ans, solve(i+1, j));
        ans = min(ans, solve(i+1, j+1));
        return dp[i][j] = (M[i][j] + ans);
    }

    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        M = matrix;
        n = M.size();
        m = M[0].size();
        memset(dp, 0xff, sizeof(dp));

        int ans = INT_MAX;
        for(int i = 0; i < m; i++)
        {
            ans = min(ans, solve(0, i));
        }
        return ans;
    }
};

int main()
{
    // skip
}