/*
 * Leetcode Medium 797. Rabbits in Forest
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
    vector<vector<int>> G;
    vector<int> p;
    vector<bool> vis;
    vector<vector<int>> ans;

    void solve(int fr, int to)
    {
        if(fr == to)
        {
            ans.push_back(p);
            return;
        }

        for(int i : G[fr])
        {
            if(!vis[i])
            {
                vis[i] = true;
                p.push_back(i);
                solve(i, to);
                p.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        G = graph;
        int n = G.size();
        vis.resize(n);

        vis[0] = true;
        p.push_back(0);
        solve(0, n-1);
        return ans;
    }
};

int main()
{

}