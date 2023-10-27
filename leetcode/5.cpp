/*
 * Leetcode Medium 5. Longest Palindromic Substring
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

#define N 1000
class Solution {
public:
    string s;
    int memo[N+5][N+5];
    bool solve(int i, int j)
    {
        if(memo[i][j] != -1)
            return memo[i][j];

        if(j-i == 0)
            return memo[i][j] = 1;
        if(j-i == 1)
            return memo[i][j] = s[i] == s[j];

        return memo[i][j] = (solve(i+1, j-1) && s[i] == s[j]);
    }
    string longestPalindrome(string s_)
    {
        s = s_;
        int n = s.size();
        string ans;
        int maxSiz = -1;
        memset(memo, 0xff, sizeof(memo));

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(solve(i, j))
                {
                    if(j-i > maxSiz)
                    {
                        maxSiz = j-i;
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}
