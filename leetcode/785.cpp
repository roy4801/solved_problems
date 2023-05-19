/*
 * Leetcode Medium 785. Is Graph Bipartite?
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

class Solution {
public:
    bool isBipartite(vector<vector<int>>& G)
    {
        vector<int> color(G.size(), -1);
        auto dfs = [&](int fr, auto&& dfs)
        {
            for(int to : G[fr])
            {
                if(color[fr] == color[to])
                    return false;
                
                if(color[to] == -1)
                {
                    color[to] = 1-color[fr];
                    if(dfs(to, dfs) == false)
                        return false;
                }
            }
            return true;
        };

        bool ans = true;
        for(int i = 0; i < G.size(); i++)
        {
            color[i] = 0;
            ans &= dfs(i, dfs);
            if(!ans) break;
            fill(color.begin(), color.end(), -1);
        }
        return ans;
    }
};

int main()
{
    // skip
}
