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
    int minCostClimbingStairs(vector<int>& c)
    {
        vector<int> cost = {0, 0};
        cost.insert(cost.begin()+1, c.begin(), c.end());
        int n = c.size();
        vector<int> dp(cost.size()+5);

        for(int i = 1; i <= n+1; i++)
        {
            if(i-2 >= 0)
                dp[i] += min(dp[i-1], dp[i-2])+cost[i];
            else
                dp[i] += cost[i];
        }
        
        return dp[n+1];
    }
};

int main()
{
    // skip
}
