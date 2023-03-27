/*
 * Leetcode Medium 64. Minimum Path Sum
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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int tmp = INT_MAX;
                tmp = min(tmp, i-1 >= 0 ? dp[i-1][j] : INT_MAX);
                tmp = min(tmp, j-1 >= 0 ? dp[i][j-1] : INT_MAX);
                if(tmp == INT_MAX)
                    tmp = 0;
                dp[i][j] = tmp + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};

int main()
{
    using InputType=vector<vector<int>>;
    vector<InputType> in = {
        {{1,3,1},{1,5,1},{4,2,1}}, // 7
        {{1,2,3},{4,5,6}},         // 12
    };
    for(auto &i : in)
    {
        DBG(Solution{}.minPathSum(i));
    }
}