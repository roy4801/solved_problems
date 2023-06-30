/*
 * Leetcode Hard 1970. Last Day Where You Can Still Cross
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

using P=pair<int,int>;
class Solution {
public:
    const int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int latestDayToCross(int n, int m, vector<vector<int>>& w)
    {
        auto bfs = [&](int k)
        {
            vector<vector<int>> c(n, vector<int>(m));
            for(int i = 0; i <= k; i++)
                c[w[i][0]-1][w[i][1]-1] = 1;

            vector<vector<bool>> vis(n, vector<bool>(m));
            queue<P> q;
            for(int j = 0; j < m; j++)
                if(!c[0][j])
                    q.emplace(0, j);
            while(!q.empty())
            {
                auto [i, j] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++)
                {
                    int ni = i+dir[d][0], nj = j+dir[d][1];
                    if(0 <= ni && ni < n && 0 <= nj && nj < m &&
                       c[ni][nj] == 0 && !vis[ni][nj])
                    {
                        vis[ni][nj] = 1;
                        q.emplace(ni, nj);
                    }
                }
            }

            for(int a = 0; a < m; a++)
                if(vis[n-1][a])
                    return true;
            return false;
        };
        
        int k = w.size();
        int l = 0, r = k;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(bfs(mid))
                l = mid+1;
            else
                r = mid;
        }

        return l;
    }
};

int main()
{
    // skip
}