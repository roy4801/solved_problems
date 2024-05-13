/*
 * Leetcode Medium 861. Score After Flipping Matrix
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
    int matrixScore(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        
        // First column must be 1 -> find max
        for(int i = 0; i < n; i++)
            if(grid[i][0] == 0)
                for(int j = 0; j < m; j++)
                    grid[i][j] = 1 - grid[i][j];
        
        // Flip the column if the #0 > #1
        for(int i = 1; i < m; i++)
        {
            int r = 0;
            for(int j = 0; j < n; j++)
                if(grid[j][i])
                    r++;

            if(n-r > r)
                for(int j = 0; j < n; j++)
                    grid[j][i] = 1 - grid[j][i];
        }

        // Compute the answer
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int num = 0;
            for(int j = 0; j < m; j++)
            {
                num <<= 1;
                num |= grid[i][j];
            }
            ans += num;
        }
        return ans;
    }
};

int main()
{
    // skip
}