/*
 * Leetcode Medium 2477. Number of Ways to Reach a Position After Exactly k Steps
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
#define N 100000
class Solution {
public:
    LL minimumFuelCost(vector<vector<int>>& e, int seat) {
        vector<vector<int>> G(e.size()+5);
        LL ans = 0;
        auto dfs = [&](int i, int par, auto &&dfs) -> LL
        {
            // 子樹有多少個人
            LL p = 1;
            for(int j : G[i])
            {
                if(j != par)
                {
                    p += dfs(j, i, dfs);
                }
            }

            if(i != 0)
            {
                ans += ceil(p / (double)seat);
            }
            return p;
        };

        for(auto &i : e)
        {
            int a = i[0], b = i[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        dfs(0, -1, dfs);

        return ans;
    }
};

int main()
{
    using InputType=pair<vector<vector<int>>, int>;
    vector<InputType> in = {
        {{{0,1},{0,2},{0,3}}, 5},
        {{{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}}, 2},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.minimumFuelCost(i.X, i.Y));
    }
}