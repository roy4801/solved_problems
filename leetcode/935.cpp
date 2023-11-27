/*
 * Leetcode Medium 935. Knight Dialer
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
    int mod = 1e9+7;
    vector<int> dp[2];
    void calc(int i)
    {
        /*
        1 2 3
        4 5 6
        7 8 9
        x 0 x
        */
        switch(i)
        {
            case 0:
                dp[1][0] = dp[0][4] + dp[0][6];
                break;
            case 1:
                dp[1][1] = dp[0][6] + dp[0][8];
                break;
            case 2:
                dp[1][2] = dp[0][7] + dp[0][9];
                break;
            case 3:
                dp[1][3] = dp[0][4] + dp[0][8];
                break;
            case 4:
            {
                dp[1][4] = dp[0][0] + dp[0][3];
                dp[1][4] %= mod;
                dp[1][4] += dp[0][9];
                break;
            }
            case 5:
                dp[1][5] = 0;
                break;
            case 6:
                dp[1][6] = dp[0][0] + dp[0][1];
                dp[1][6] %= mod;
                dp[1][6] += dp[0][7];
                break;
            case 7:
                dp[1][7] = dp[0][2] + dp[0][6];
                break;
            case 8:
                dp[1][8] = dp[0][1] + dp[0][3];
                break;
            case 9:
                dp[1][9] = dp[0][2] + dp[0][4];
                break;
        }
        dp[1][i] %= mod;
    }
    int knightDialer(int n)
    {
        dp[0].resize(10, 1);
        dp[1].resize(10, 1);

        while(--n)
        {
            for(int i = 0; i < 10; i++)
                calc(i);
            dp[0] = dp[1];
        }

        int ans = 0;
        for(int i = 0; i < 10; i++)
        {
            ans += dp[1][i];
            ans %= mod;
        }

        return ans;
    }
};

int main()
{
    // skip
}