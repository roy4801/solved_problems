/*
 * Leetcode Medium 1514. Path with Maximum Probability
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

using P=pair<double,int>;
class Solution {
public:
    double eps = 1e-5;
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& prob, int st, int en) {
        vector<vector<pair<int,double>>> G(n); // [fr] -> {(to, wei), ...}

        for(int i = 0; i < e.size(); i++)
        {
            int fr = e[i][0], to = e[i][1];
            double p = prob[i];
            G[fr].emplace_back(to, p);
            G[to].emplace_back(fr, p);
        }

        vector<double> dis(n, 10.0);
        priority_queue<P> pq;
        
        pq.emplace(1.0, st);
        while(!pq.empty())
        {
            auto [wei, cur] = pq.top();
            pq.pop();

            if(dis[cur] <= 1.0)
                continue;

            dis[cur] = wei;

            for(auto [to, p] : G[cur])
            {
                if(dis[to] > 1.0)
                {
                    pq.emplace(dis[cur]*p, to);
                }
            }
        }

        return dis[en] <= 1.0 ? dis[en] : 0.0;
    }
};

class Solution {
public:
    using P=pair<int, double>;
    double maxProbability(int n, vector<vector<int>>& edge, vector<double>& prob, int st, int en)
    {
        int m = edge.size();
        vector<vector<P>> G(n); // [from idx] = (to idx, probability)
        vector<double> d(n, -1.0); // [idx] = max probability

        for(int i = 0; i < m; i++)
        {
            int a = edge[i][0], b = edge[i][1];
            G[a].emplace_back(b, prob[i]);
            G[b].emplace_back(a, prob[i]);
        }

        priority_queue<pair<double,int>> pq; // probability, idx
        pq.emplace(1.0, st);
        while(!pq.empty())
        {
            auto [p, i] = pq.top(); pq.pop();
            
            if(d[i] != -1.0)
                continue;
            d[i] = p;

            for(auto [j, w] : G[i])
            {
                pq.emplace(p * w, j);
            }
        }

        return d[en] == -1.0 ? 0.0 : d[en];
    }
};

int main()
{
    // skip
}