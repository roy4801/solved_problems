/*
 * Leetcode Easy 509. Fibonacci Number
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
    int dp[35];
    int fib(int n) {
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= 30; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

int main()
{
    // skip
}