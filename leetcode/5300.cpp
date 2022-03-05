/*
 * Leetcode Medium 5300. All Ancestors of a Node in a Directed Acyclic Graph
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back
#define N 1000
class Solution
{
public:
    vector<int> G[N+5];

    vector<int> an; // ancestors
    bool vis[N+5];
    void dfs(int r)
    {
        for(int i : G[r])
        {
            if(!vis[i])
            {
                an.push_back(i);
                vis[i] = true;
                dfs(i);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e)
    {
        vector<vector<int>> ans;
        for(auto &&i : e)
        {
            int a = i[0], b = i[1];
            G[b].PB(a);
        }

        for(int i = 0; i < n; i++)
        {
            memset(vis, false, sizeof(vis));
            an.clear();
            //
            vis[i] = true;
            dfs(i);
            sort(an.begin(), an.end());
            ans.PB(an);
        }
        return ans;
    }
};

int main()
{
    int n = 8;
    vector<vector<int>> e = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    auto ans = Solution{}.getAncestors(n, e);
    DBG(ans);
}