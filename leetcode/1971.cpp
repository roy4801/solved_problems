/*
 * Leetcode Easy 1971. Find if Path Exists in Graph
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

#define N 200000
struct Disjoint
{
    int p[N+5];
    void init(int n)
    {
        for(int i = 0; i <= n; i++)
            p[i] = i;
    }
    int find(int x)
    {
        return (p[x]==x) ? x : (p[x] = find(p[x]));
    }
    void uni(int a, int b)
    {
        p[find(a)] = find(b);
    }
};

class Solution {
public:
    Disjoint set;
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst)
    {
        set.init(n);
        for(auto i : edges)
        {
            auto &&[a, b] = tie(i[0], i[1]);
            set.uni(a, b);
        }
        // printf("> %d %d\n", set.find(src), set.find(dst));
        return set.find(src) == set.find(dst);
    }
};

// DFS
class Solution2 {
public:
    vector<int> G[N+5];
    bool vis[N+5];
    bool ans = false;

    void dfs(int s, int d)
    {
        //printf("> %d %d\n", s, d);
        // vis[s] = true;

        if(s == d)
        {
            ans = true;
            return;
        }

        for(int i : G[s])
        {
            if(!vis[i])
            {
                vis[i] = true;
                dfs(i, d);
                // vis[i] = false; TLE!
            }
        }
        // vis[s] = false;
    }

    bool validPath(int n, vector<vector<int>>& e, int src, int dst)
    {
        // build
        for(auto &i : e)
        {
            auto &&[a, b] = tie(i[0], i[1]);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(vis, 0, sizeof(vis));
        vis[src] = true;
        dfs(src, dst);
        return ans;
    }
};

// dfs (iteratively)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst)
    {
        vector<vector<int>> G(n);
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        stack<int> s;
        vector<bool> vis(n, 0);
        vis[src] = 1;
        s.push(src);
        while(!s.empty())
        {
            int i = s.top();
            s.pop();

            for(auto j : G[i])
            {
                if(!vis[j])
                {
                    s.push(j);
                    vis[j] = 1;
                }
            }
        }
        
        return vis[dst];
    }
};

// disjoint (lambda)
class Solution {
public:
    vector<int> p;
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst)
    {
        p.resize(n+5);
        for(int i = 0; i <= n; i++)
            p[i] = i;

        function<int(int)> Find;
        Find = [&](int x) -> int {
            return x == p[x] ? x : (p[x]=Find(p[x]));
        };
        auto Union = [&](int a, int b) -> void {
            p[Find(a)] = Find(b);
        };
        auto IsSame = [&](int a, int b) -> bool {
            return Find(a) == Find(b);
        };

        for(auto e : edges)
        {
            int a = e[0], b = e[1];
            Union(a, b);
        }
        return IsSame(src, dst);
    }
};

int main()
{
    // skip
}