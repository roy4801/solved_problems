/*
 * Leetcode Medium 59. Spiral Matrix II
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

#define N 400

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> M(n, vector<int>(n));

        int i = 0, j = 0;
        int cur = 1;
        int dir = 0;
        P dirOff[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        bool vis[N+5];
        auto isEnd = [&]()
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(!vis[i*n+j])
                        return false;
            return true;
        };
        auto check = [&](int i, int j)
        {
            return (0 <= i && i < n && 0 <= j && j < n) && !vis[i*n+j];
        };

        memset(vis, 0, sizeof(vis));
        vis[0] = true;
        M[0][0] = cur++;
        while(!isEnd())
        {
            int ni = i + dirOff[dir].X,
                nj = j + dirOff[dir].Y;
            if(!check(ni, nj))
            {
                dir++;
                if(dir >= 4)
                    dir -= 4;
                continue;
            }
            else
            {
                i = ni;
                j = nj;
                M[i][j] = cur++;
                vis[i*n+j] = true;
            }
        }
        return M;
    }
};

int main()
{
    // skip
}
