/*
 * Leetcode Medium 3071. Minimum Operations to Write the Letter Y on a Grid
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
    set<pair<int,int>> s;
    inline bool isY(int i, int j)
    {
        return s.count({i, j});
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid)
    {
        int n = grid.size();
        s.clear();
        
        for(int i = 0; i <= n/2; i++)
        {
            for(int j = 0; j <= n/2; j++)
                if(i == j)
                {
                    s.emplace(i, j);
                    s.emplace(n/2-i, n/2+j);
                }
            s.emplace(n/2+i, n/2);
        }
        
        int in[3] = {0}, out[3] = {0};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isY(i, j))
                    in[grid[i][j]]++;
                else
                    out[grid[i][j]]++;
                
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i <= 2; i++) // in
            for(int j = 0; j <= 2; j++) // out
            {
                if(i == j)
                    continue;
                int tmp = 0;
                for(int k = 0; k < 3; k++)
                    if(k != i)
                        tmp += in[k];
                for(int k = 0; k < 3; k++)
                    if(k != j)
                        tmp += out[k];
                ans = min(ans, tmp);
            }
        
        return ans;
    }
};

int main()
{
    // skip
}