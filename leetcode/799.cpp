/*
 * Leetcode Medium 799. Champagne Tower
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back
#define N 100

#define N 100

class Solution
{
public:
    double b[N+5][N+5];
    double bottom_up(int p, int r, int c)
    {
        b[0][0] = p;
        
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j > 0 && b[i-1][j-1] > 1.0)
                {
                    b[i][j] += (b[i-1][j-1]-1.0) / 2.0;
                }
                if(j < i && b[i-1][j] > 1.0)
                {
                    b[i][j] += (b[i-1][j]-1.0) / 2.0;
                }
            }
        }

        return b[r][c] >= 1.0 ? 1.0 : b[r][c];
    }
    
    double dp[105][105];
    double top_down(int r, int c)
    {
        if(c < 0 || c > r)
            return 0;
        if(r == 0 && c == 0)
            return dp[0][0];

        if(dp[r][c] != -1.0)
            return dp[r][c];

        return dp[r][c] = (max(top_down(r-1, c-1)-1, 0.0) / 2.0 
                         + max(top_down(r-1, c)-1, 0.0) / 2.0);
    }
//     for(int i = 0; i <= r; i++)
//         for(int j = 0; j <= c; j++)
//             dp[i][j] = -1.0;

//     dp[0][0] = p;
//     return min(1.0, top_down(r, c));
    
    double champagneTower(int p, int r, int c)
    {
        return bottom_up(p, r, c);
    }
};



int main()
{
    auto x = Solution{};
    // cout << x.champagneTower(100000009, 33, 17) << '\n';
    cout << x.champagneTower(2, 1, 1) << '\n';
    // x.dbg(0, 3);
}