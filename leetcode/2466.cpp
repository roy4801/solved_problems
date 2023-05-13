/*
 * Leetcode Medium 2466. Count Ways To Build Good Strings
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

#define MOD 1000000007

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high+5, 0); // i = size of string, dp[i] = num of string that size are i
        dp[0] = 1;

        for(int i = 1; i <= high; i++)
        {
            if(i - zero >= 0)
            {
                dp[i] += dp[i - zero];
                dp[i] %= MOD;
            }
            if(i - one >= 0)
            {
                dp[i] += dp[i - one];
                dp[i] %= MOD;
            }
        }
        
        int ans = 0;
        for(int i = low; i <= high; i++)
            ans = (ans + dp[i]) % MOD;

        return ans;
    }
};

int main()
{
    // skip
}