/*
 * Leetcode Hard 296. Best Meeting Point
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
    inline int distance(P a, P b)
    {
        return abs(a.X-b.X)+abs(a.Y-b.Y);
    }
    int minTotalDistance(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> x, y;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        int k = x.size(), h = k/2;
        nth_element(x.begin(), x.begin() + h, x.end());
        nth_element(y.begin(), y.begin() + h, y.end());

        int ans = 0;
        for(int i = 0; i < k; i++)
            ans += distance({x[i], y[i]}, {x[h], y[h]});

        return ans;
    }
};

int main()
{
    // skip
}