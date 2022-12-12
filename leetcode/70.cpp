/*
 * Leetcode Easy 70. Climbing Stairs
 * author: roy4801
 * AC(C++) 0ms
 */
#include <bits/stdc++.h>
using namespace std;
#include "leetcode_helper.h"
#include "helper.h"

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

int main()
{
    // skip
}