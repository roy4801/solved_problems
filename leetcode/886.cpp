/*
 * Leetcode Medium 886. Possible Bipartition
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

#define N 2000
class Solution
{
public:
    vector<int> G[N+5];
    int color[N+5]; // -1 = no color, 0 = color a, 1 = color b
    int n;

    void build(int _n, vector<vector<int>>& E)
    {
        n = _n;
        for(auto it : E)
        {
            int a = it[0], b = it[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }

    bool dfs(int fr)
    {
        for(int to : G[fr])
        {
            if(color[fr] == color[to])
                return false;

            if(color[to] == -1)
            {
                color[to] = 1 - color[fr]; // diff color
                if(!dfs(to))
                    return false;
            }
        }
        return true;
    }

    bool isBipartirate()
    {
        bool ok = true;
        for(int i = 1; i <= n; i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                ok = ok & dfs(i);
            }
        }
        return ok;
    }

    bool possibleBipartition(int n, vector<vector<int>>& edges)
    {
        memset(color, 0xff, sizeof(color)); // set to -1
        build(n, edges);
        return isBipartirate();
    }
};

int main()
{
    // skip
}