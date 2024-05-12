/*
 * Leetcode Easy 2373. Largest Local Values in a Matrix
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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));

        auto findMax = [&](int i, int j)
        {
            int m = INT_MIN;
            for(int a = i-1; a <= i+1; a++)
                for(int b = j-1; b <= j+1; b++)
                    m = max(m, grid[a][b]);
            return m;
        };

        for(int i = 1; i <= n-2; i++)
            for(int j = 1; j <= n-2; j++)
                ans[i-1][j-1] = findMax(i, j);

        return ans;
    }
};

int main()
{
    // skip
}