/*
 * Leetcode Medium 198. House Robber
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

#define N 400
class Solution {
public:
    int n;
    int W[N+5] = {0};
    
    // buttom-up
    int dp[N+5];
    void build()
    {
        dp[0] = 0; // = W[0]
        dp[1] = W[1];
        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i-2]+W[i], dp[i-1]);
        }
    }

    int rob(vector<int>& nums)
    {
        n = nums.size();
        copy(nums.begin(), nums.end(), W+1);
        build();
        return dp[n];
    }
};

int main()
{
    // skip
}