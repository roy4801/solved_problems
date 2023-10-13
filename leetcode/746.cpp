/*
 * Leetcode Easy 746. Min Cost Climbing Stairs
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
    int n;
    vector<int> cost;
    vector<int> dp;

    int minCostClimbingStairs(vector<int>& c)
    {
        n = c.size();
        cost = {0, 0};
        cost.insert(cost.begin()+1, c.begin(), c.end());
        dp.resize(cost.size()+5);

        for(int i = 1; i <= n+1; i++)
        {
            if(i-2 >= 0)
                dp[i] += min(dp[i-1]+cost[i], dp[i-2]+cost[i]);
            else if(i-1 >= 0)
                dp[i] += dp[i-1]+cost[i];
        }

        return dp[n+1];
    }
};

int main()
{
    // skip
}
