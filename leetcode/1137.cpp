/*
 * Leetcode Easy 1137. N-th Tribonacci Number
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

class Solution {
public:
    int dp[40] = {0, 1, 1};
    int tribonacci(int n) {
        if(n <= 3)
            return dp[n];
        return dp[n] = (tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3));
    }
};

class Solution {
public:
    int dp[40];
    Solution()
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= 37; i++)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int tribonacci(int n)
    {
        return dp[n];
    }
};

int main()
{
    // skip
}
