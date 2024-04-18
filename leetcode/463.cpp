/*
 * Leetcode Easy 463. Island Perimeter
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
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    continue;
                ans += (i-1 >= 0 && grid[i-1][j]) ? 0 : 1;
                ans += (i+1 < n && grid[i+1][j]) ? 0 : 1;
                ans += (j-1 >= 0 && grid[i][j-1]) ? 0 : 1;
                ans += (j+1 < m && grid[i][j+1]) ? 0 : 1;
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}
