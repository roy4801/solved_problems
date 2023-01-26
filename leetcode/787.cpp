/*
 * Leetcode Medium 787. Cheapest Flights Within K Stops
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
#define INF 0x3f3f3f3f

#define N 100
class Solution {
public:
    int n, k, src, dst;
    vector<vector<P>> G; // [from] -> (to, weight)
    void build(vector<vector<int>>& E)
    {
        G.assign(n, {});
        for(auto &e : E)
            G[e[0]].push_back(MP(e[1], e[2]));
    }

    vector<int> depth;
    using S=tuple<int,int,int>;
    int dijk(int src)
    {
        depth.assign(n, INF);
        priority_queue<S, vector<S>, greater<S>> pq; // (distance, node idx, depth)
        int curIdx, to, curWei, wei, curDep;

        pq.emplace(0, src, 0);
        while(!pq.empty())
        {
            tie(curWei, curIdx, curDep) = pq.top(); pq.pop();

            if(curDep > depth[curIdx] || curDep > k+1)
                continue;

            depth[curIdx] = curDep;

            if(curIdx == dst)
                return curWei;

            for(auto j : G[curIdx])
            {
                tie(to, wei) = j;
                if(curDep <= depth[curIdx])
                    pq.emplace(curWei+wei, to, curDep+1);
            }
        }
        return -1;
    }

    int findCheapestPrice(int _n, vector<vector<int>>& e, int _src, int _dst, int _k) {
        n = _n;
        k = _k;
        src = _src;
        dst = _dst;
        build(e);
        return dijk(src);
    }
};

int main()
{
    using InputType=tuple<int, vector<vector<int>>, int, int, int>;
    vector<InputType> in = {
        {4, {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}}, 0, 3, 1},
        {3, {{0,1,100},{1,2,100},{0,2,500}}, 0, 2, 1},
        {3, {{0,1,100},{1,2,100},{0,2,500}}, 0, 2, 0},
    };
    for(auto &i : in)
    {
        auto n = get<0>(i);
        auto &e = get<1>(i);
        auto src = get<2>(i);
        auto dst = get<3>(i);
        auto k = get<4>(i);
        DBG(Solution{}.findCheapestPrice(n, e, src, dst, k));
    }
}