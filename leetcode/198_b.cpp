/*
 * Leetcode Medium 198. House Robber
 * author: roy4801
 * (C++)
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
    // top-down
    int dp[N+5];
    int solve(int i)
    {
        if(i == 0 || i == 1)
            return W[i];
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(W[i] + solve(i-2), solve(i-1));
    }

    int rob(vector<int>& nums)
    {
        n = nums.size();
        copy(nums.begin(), nums.end(), W+1);
        memset(dp, 0xff, sizeof(dp));
        return solve(n);
    }
};

int main()
{
    // skip
}