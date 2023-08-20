/*
 * Leetcode Medium 207. Course Schedule
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

// dfs coloring
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq)
    {
        int m = preq.size();
        vector<char> color(n); // 0, 1, 2
        vector<vector<int>> req(n, vector<int>{});

        function<bool(int)> dfs = [&](int x) -> bool
        {
            color[x] = 1;
            for(int y : req[x])
            {
                if(color[y] == 0)
                {
                    color[y] = 1;
                    if(dfs(y))
                        return 1;
                }
                else if(color[y] == 1)
                    return 1;
            }
            color[x] = 2;
            return 0;
        };

        for(int i = 0; i < m; i++)
        {
            int a = preq[i][0], b = preq[i][1];
            req[a].push_back(b);
        }

        for(int i = 0; i < n; i++)
            if(color[i] == 0 && dfs(i))
                return 0;
        return 1;
    }
};

// topological sort
class Solution2 {
public:
    bool canFinish(int n, vector<vector<int>>& preq)
    {
        // 建圖
        vector<vector<int>> G(n);
        for(auto &i : preq)
        {
            int a = i[0], b = i[1];
            G[a].push_back(b);
        }
        // 統計每個點的入度
        vector<int> conn(n); // in-degree
        for(int i = 0; i < n; i++)
            for(auto j : G[i])
                conn[j]++;
        // 找起始點 (入度=0的)，蒐集到 q 中
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(conn[i] == 0)
                q.push(i);
        // 將 q 裡的點拔掉
        vector<int> topo;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            topo.push_back(cur);
            // 把 cur 連出去的邊都拔掉
            for(int j : G[cur])
            {
                conn[j]--;
                if(conn[j] == 0)
                    q.push(j);
            }
        }
        // 如果「拓撲排序的點數」不等於「圖的點數」，代表無法排出拓撲排序(有環)
        return topo.size() == n;
    }
};

int main()
{
    // skip
}
