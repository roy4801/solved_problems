/*
 * Leetcode Medium 399. Evaluate Division
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

using P=pair<int, double>;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q)
    {
        vector<double> ans;

        int n = e.size();
        vector<P> G[30];             // G[from] = {to, weight}
        vector<bool> vis(30, false); // i = node id, vis[i] = is the node visited
        
        // convert str to node id (int) for graph
        int gid = 0;
        map<string, int> mm;
        auto id = [&](string &c) { return mm.count(c) ? mm[c] : (mm[c] = gid++); };
        
        // dfs from node `fr` to node `end`
        double dfsAns;
        auto dfs = [&](int fr, int end, double val, auto&& dfs)
        {
            if(fr == end)
            {
                dfsAns = val;
                return true;
            }

            for(auto &e : G[fr])
            {
                auto&& [to, wei] = e;
                if(!vis[to])
                {
                    vis[to] = true;
                    if(dfs(to, end, val*wei, dfs))
                        return true;
                }
            }
            return false;
        };

        // build graph
        for(int i = 0; i < n; i++)
        {
            int a = id(e[i][0]), b = id(e[i][1]);

            G[a].emplace_back(b, v[i]);
            G[b].emplace_back(a, 1.0/v[i]);
        }
        // solve query
        for(auto &i : q)
        {
            auto a = i[0], b = i[1];
            if(!mm.count(a) || !mm.count(b))
            {
                ans.push_back(-1.0);
                continue;
            }
            if(a == b)
            {
                ans.push_back(1.0);
                continue;
            }
            int fr = id(a), to = id(b);

            fill(vis.begin(), vis.end(), false);
            bool ok = dfs(fr, to, 1.0, dfs);

            ans.push_back(ok ? dfsAns : -1.0);
        }

        return ans;
    }
};

int main()
{
    // skip
}
