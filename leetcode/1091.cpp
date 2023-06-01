/*
 * Leetcode Medium 1091. Shortest Path in Binary Matrix
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
#define arr array
class Solution {
public:
    int dir[3] = {-1, 0, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& g)
    {
        int n = g.size();
        int ans = INT_MAX;

        auto ok = [&](int x)
        {
            return x >= 0 && x <= n-1;
        };
        auto bfs = [&](int i, int j)
        {
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<arr<int,3>> q;
            if(!g[i][j])
            {
                q.push({i, j, 1});
                vis[i][j] = true;
            }

            while(!q.empty())
            {
                auto [x, y, dis] = q.front(); q.pop();

                if(x == n-1 && y == n-1)
                {
                    ans = min(ans, dis);
                }

                for(int a : dir)
                {
                    for(int b : dir)
                    {
                        int xx = x+a, yy = y+b;
                        if(ok(xx) && ok(yy) && !g[xx][yy] && !vis[xx][yy])
                        {
                            q.push({xx, yy, dis+1});
                            vis[xx][yy] = true;
                        }
                    }
                }
            }
        };

        bfs(0, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    // skip
}
