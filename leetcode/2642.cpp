/*
 * Leetcode Hard 2642. Design Graph With Shortest Path Calculator
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

class Graph {
public:
    const int inf = 1e6+1;
    int n;
    vector<vector<P>> G; // [from] -> (to, weight)
    priority_queue<P,vector<P>,greater<>> pq; // (weight, index)
    vector<int> dis;
    Graph(int n_, vector<vector<int>>& edges)
    {
        n = n_;
        G.resize(n);
        dis.resize(n);
        for(auto &i : edges)
        {
            auto [a, b, w] = tie(i[0], i[1], i[2]);
            G[a].emplace_back(b, w);
        }
    }
    
    void addEdge(vector<int> edge)
    {
        auto [a, b, w] = tie(edge[0], edge[1], edge[2]);
        G[a].emplace_back(b, w);
    }
    
    int shortestPath(int a, int b)
    {
        pq = {};
        for(int i = 0; i < n; i++)
            dis[i] = inf;

        pq.emplace(0, a);
        while(!pq.empty())
        {
            auto [w, cur] = pq.top();
            pq.pop();

            if(dis[cur] != inf)
                continue;

            dis[cur] = w;
            for(auto [to, wei] : G[cur])
            {
                if(dis[to] == inf)
                {
                    pq.emplace(dis[cur]+wei, to); // goto index "to"
                }
            }
        }

        return dis[b] == inf ? -1 : dis[b];
    }
};

int main()
{
    // skip
}