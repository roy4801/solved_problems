/*
 * Leetcode Easy 70. Climbing Stairs
 * author: roy4801
 * AC(C++) 0ms
 */
#include <bits/stdc++.h>
using namespace std;
#include "leetcode_helper.h"
#include "helper.h"
// Buttom-Up
class Solution {
public:
    int dp[50];
    int climbStairs(int n) {
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= 45; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Top-Down
class Solution2 {
public:
    int memo[50];
    Solution()
    {
        memset(memo, 0xff, sizeof(memo));
    }
    int solve(int i)
    {
        if(memo[i] != -1)
            return memo[i];
        if(i == 0 || i == 1)
            return 1;
        return memo[i] = (solve(i-1) + solve(i-2));
    }
    int climbStairs(int n) {
        return solve(n);
    }
};


int main()
{
    // skip
}
