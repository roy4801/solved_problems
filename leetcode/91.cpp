/*
 * Leetcode Medium 91. Decode Ways
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
    string s;
    int n;
    int cnt;
    inline bool ok(int i)
    {
        return 1 <= i && i <= 26;
    }
    int dp[105];
    int solve(int i)
    {
        if(dp[i] != -1)
            return dp[i];
        if(s[i] == '0')
            return 0;
        if(i >= n-1)
            return 1;
        return dp[i] = (solve(i+1) + (ok(stoi(s.substr(i,2))) ? solve(i+2) : 0));
    }
    int numDecodings(string s)
    {
        this->s = s;
        n = s.size();
        cnt = 0;
        memset(dp, 0xff, sizeof(dp));
        return solve(0);
    }
};

int main()
{
    // skip
}