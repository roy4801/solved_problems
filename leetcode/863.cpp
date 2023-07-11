/*
 * Leetcode Medium 863. All Nodes Distance K in Binary Tree
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

class Solution {
public:
    vector<vector<int>> G;
    map<TreeNode*, int> N;
    map<int,TreeNode*> NN;
    int id = 0;
    int getId(TreeNode *n)
    {
        if(!N.count(n))
        {
            NN[id] = n;
            N[n] = id++;
            G.push_back({});
        }
        return N[n];
    }
    void build(TreeNode *n)
    {
        if(!n) return;
        if(n->left)
        {
            int a = getId(n), b = getId(n->left);
            G[a].push_back(b);
            G[b].push_back(a);
            build(n->left);
        }
        if(n->right)
        {
            int a = getId(n), b = getId(n->right);
            G[a].push_back(b);
            G[b].push_back(a);
            build(n->right);
        }
    }
    vector<int> ans;
    void bfs(int s, int k)
    {
        using P=pair<int,int>;
        vector<bool> vis(N.size());
        queue<P> q;
        q.emplace(s, 0);
        while(!q.empty())
        {
            auto [cur, dep] = q.front();
            q.pop();

            if(dep >= k)
            {
                if(cur != s)
                    ans.push_back(cur);
                continue;
            }

            for(auto to : G[cur])
            {
                if(!vis[to])
                {
                    vis[to] = true;
                    q.emplace(to, dep+1);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* r, TreeNode* t, int k)
    {
        if(k == 0)
            return {t->val};
        build(r);
        int s = getId(t);
        bfs(s, k);
        for_each(ans.begin(), ans.end(), [&](auto &i) { i = NN[i]->val; });
        return ans;
    }
};

int main()
{
    // skip
}
