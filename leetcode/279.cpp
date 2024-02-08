/*
 * Leetcode Medium 279. Perfect Squares
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

#define N 100
class Solution {
public:
    int memo[10005];
    int solve(int n)
    {
        if(memo[n] != -1)
            return memo[n];
        int ans = INT_MAX;
        for(int i = 1; i <= N; i++)
        {
            int cur = i*i;
            if(n < cur)
                break;
            ans = min(ans, solve(n-cur)+1);
        }
        return memo[n] = (ans == INT_MAX ? 0 : ans);
    }

    int numSquares(int n)
    {
        memset(memo, 0xff, sizeof(memo));
        return solve(n);
    }
};

int main()
{
    // skip
}