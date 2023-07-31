/*
 * Leetcode Medium 712. Minimum ASCII Delete Sum for Two Strings
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
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+5, vector<int>(m+5, -1));
        auto solve = [&](int i, int j, auto&& solve) -> int
        {
            if(i < 0 || j < 0)
                return 0;
            if(dp[i][j] != -1)
                return dp[i][j];

            int sum = 0;
            if(s1[i] == s2[j])
            {
                sum += s1[i] + solve(i-1, j-1, solve);
            }
            else
            {
                sum += max(solve(i-1, j, solve), solve(i, j-1, solve));
            }
            return dp[i][j] = sum;
        };

        int ans = 0;
        ans = accumulate(s1.begin(), s1.end(), ans);
        ans = accumulate(s2.begin(), s2.end(), ans);
        ans -= 2*solve(n, m, solve);
        return ans;
    }
};

int main()
{
    // skip
}