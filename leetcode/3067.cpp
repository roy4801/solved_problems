/*
 * Leetcode Medium 3067. Count Pairs of Connectable Servers in a Weighted Tree Network
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

using P = pair<int,int>;
class Solution {
public:
    vector<vector<P>> G;
    int ss;
    // 對於點 i 當根節點，w="到達點 i 累積的路徑長"
    int dfs(int i, int parent, int w)
    {
        // 當前點(i)符不符合規則
        int cnt = w % ss == 0 ? 1 : 0;
        for(auto [j, wei] : G[i]) // j 的 child
        {
            if(j != parent) // 不往回走
            {
                // 累計符合規則的點
                cnt += dfs(j, i, w + wei);
            }
        }
        return cnt;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int ss)
    {
        // 建圖
        int n = edges.size()+1;
        this->ss = ss;
        G.resize(n);
        for(auto& e : edges)
        {
            G[e[0]].push_back({e[1], e[2]});
            G[e[1]].push_back({e[0], e[2]});
        }

        vector<int> ans(n);
        // 枚舉每個點 i 當成根
        for(int i = 0; i < n; i++)
        {
            int node = 0;
            for(auto [j, wei] : G[i]) // 對於點 i 的所有 sub-node
            {
                // 去 dfs 看有多少點是符合 "路徑長 % ss == 0" 的點的數量
                int cnt = dfs(j, i, wei);
                // cnt = j 底下有多少點符合規則
                // node = 目前為止有多少點符合規則
                // 對於新加入的點來說，都可以與舊的點存在一條路徑相連，所以相乘
                ans[i] += node * cnt;
                // 累積點數量
                node += cnt;
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}