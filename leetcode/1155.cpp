/*
 * Leetcode diff 1155. Number of Dice Rolls With Target Sum
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
    const int mod = 1e9+7;
    int n, k, t;
    int memo[35][1005];
    int solve(int i, int sum)
    {
        if(memo[i][sum] != -1)
            return memo[i][sum];

        if(i >= n)
        {
            return sum == t;
        }

        int ans = 0;
        for(int d = 1; d <= k; d++)
        {
            ans += solve(i+1, sum+d);
            ans %= mod;
        }

        return memo[i][sum] = ans;
    }
    int numRollsToTarget(int _n, int _k, int target)
    {
        n = _n;
        t = target;
        k = _k;
        memset(memo, 0xff, sizeof(memo));
        return solve(0, 0);
    }
};

int main()
{
    // skip
}