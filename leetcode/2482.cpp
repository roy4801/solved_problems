/*
 * Leetcode Medium 2482. Difference Between Ones and Zeros in Row and Column
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
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<array<int,2>> row(n), col(m);

        for(int i = 0; i < m; i++)
        {
            array<int,2> arr{};
            for(int j = 0; j < n; j++)
            {
                if(grid[j][i] == 1)
                    arr[1]++;
                else
                    arr[0]++;
            }

            col[i] = arr;
        }

        for(int i = 0; i < n; i++)
        {
            array<int,2> arr{};
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    arr[1]++;
                else
                    arr[0]++;
            }

            row[i] = arr;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans[i][j] = col[j][1] + row[i][1] - col[j][0] - row[i][0];

        return ans;
    }
};

int main()
{
    // skip
}
