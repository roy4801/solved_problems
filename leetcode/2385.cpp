/*
 * Leetcode Medium 2385. Amount of Time for Binary Tree to Be Infected
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

class Solution
{
public:
    // node to id
    unordered_map<TreeNode*, int> g;
    int gid = 0;
    int getID(TreeNode* p)
    {
        if(!g.count(p))
        {
            g[p] = gid++;
            G.resize(gid);
        }
        return g[p];
    }
    // graph
    vector<vector<int>> G;
    void addEdge(int a, int b)
    {
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int st; // starting node
    void build(TreeNode* n, int x)
    {
        if(n->val == x)
        {
            st = getID(n);
        }

        if(n->left)
        {
            addEdge(getID(n), getID(n->left));
            build(n->left, x);
        }
        if(n->right)
        {
            addEdge(getID(n), getID(n->right));
            build(n->right, x);
        }
    }

    int bfs(int x)
    {
        int ans = INT_MIN;
        queue<pair<int,int>> q; // depth, idx
        unordered_set<int> vis;
        q.emplace(0, x);
        vis.insert(x);
        while(!q.empty())
        {
            auto [depth, i] = q.front();
            ans = max(ans, depth);
            q.pop();
            for(auto j : G[i])
            {
                if(!vis.count(j))
                {
                    q.emplace(depth+1, j);
                    vis.insert(j);
                }
            }
        }
        return ans;
    }

    int amountOfTime(TreeNode* r, int s)
    {
        gid = 0;
        g.clear();
        G.clear();

        build(r, s);
        return bfs(st);
    }
};

int main()
{
    // skip
}