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

class Solution
{
public:
    double b[N+5][N+5];

    double champagneTower(int p, int r, int g)
    {
        b[0][0] = p;
        
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j > 0)
                {
                    if(b[i-1][j-1] > 1.0)
                    {
                        b[i][j] += (b[i-1][j-1]-1.0) / 2.0;
                    }
                }
                if(j < i)
                {
                    if(b[i-1][j] > 1.0)
                    {
                        b[i][j] += (b[i-1][j]-1.0) / 2.0;
                    }
                }
            }
        }

        return b[r][g] >= 1.0 ? 1.0 : b[r][g];
    }

    /*void dbg(int start, int end)
    {
        for(int i = start; i < end; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                printf("%.2lf%s", b[i][j], (j == i ? "\n" : " "));
            }
        }
    }*/
};



int main()
{
    auto x = Solution{};
    // cout << x.champagneTower(100000009, 33, 17) << '\n';
    cout << x.champagneTower(2, 1, 1) << '\n';
    // x.dbg(0, 3);
}