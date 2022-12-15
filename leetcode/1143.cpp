/*
 * Leetcode Medium 1143. Find Smallest Common Element in All Rows
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

#define N 1000
class Solution {
public:
    int dp[N+5][N+5];
    int longestCommonSubsequence(string a, string b)
    {
        // build
        for(int i = 1; i <= a.size(); i++)
        {
            for(int j = 1; j <= b.size(); j++)
            {
                if(a[i-1] != b[j-1])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
            }
        }
        return dp[a.size()][b.size()];
    }
};

int main()
{
    // skip
}