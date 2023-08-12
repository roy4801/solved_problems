/*
 * Leetcode Medium 63. Unique Paths II
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

// Bottom up
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob)
    {
        int m = ob.size(), n = ob[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[1][1] = ob[0][0] ? 0 : 1;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == 1 && j == 1)
                    continue;
                if(ob[i-1][j-1])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

// Top down (memo)
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob)
    {
        int m = ob.size(), n = ob[0].size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        auto solve = [&](int i, int j, auto&& solve) -> int
        {
            if(memo[i][j] != -1)
                return memo[i][j];

            if(i <= 0 || j <= 0)
                return 0;
            if(ob[i-1][j-1])
                return 0;
            if(i == 1 && j == 1)
                return 1;

            return memo[i][j] = solve(i-1, j, solve) + solve(i, j-1, solve);
        };
        return solve(m, n, solve);
    }
};

int main()
{
    using InputType=vector<vector<int>>;
    vector<InputType> in = {
        {{0,0,0},{0,1,0},{0,0,0}},
        {{0,1},{0,0}},
        {{1}},
        {{0,0,0},{0,0,0},{0,0,0}},
        {{1,0,0},{0,0,0},{0,0,0}},
    };
    for(auto &i : in)
        DBG(Solution2{}.uniquePathsWithObstacles(i));
}