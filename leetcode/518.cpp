/*
 * Leetcode Medium 518. Coin Change II
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
    int n, t;
    vector<int> v;
    vector<vector<int>> dp;

    // 使用 [0, i] 貨幣要湊到 m 的方法數 
    int solve(int i, int m)
    {
        // 終止條件
        if(i >= n)
            return m == 0 ? 1 : 0;
        if(dp[i][m] != -1)
            return dp[i][m];

        // 搜索挑第 i 種貨幣，挑 [0, j] 次下去搜索，總價值不能超過 m
        int sum = 0;
        for(int j = 0; j * v[i] <= m; j++)
            sum += solve(i+1, m - j*v[i]); // 盡可能地挑完第 i 種貨幣
        
        return dp[i][m] = sum;
    }

    int change(int amount, vector<int>& coins)
    {
        t = amount;
        n = coins.size();
        v = coins;
        dp.resize(n+1, vector<int>(t+1, -1));
        return solve(0, t);
    }
};

int main()
{
    // skip
}