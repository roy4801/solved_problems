/*
 * Leetcode Easy 392. Is Subsequence
 * author: roy4801
 * AC(C++) 4ms 10.8MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution {
public:
    
    int dp[105][10005];
    inline bool buildDP(string &a, string &b)
    {
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= a.size(); i++)
            for(int j = 1; j <= b.size(); j++)
            {
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        
        // for(int i = 0; i <= a.size(); i++)
        //     for(int j = 0; j <= b.size(); j++)
        //         printf("%d%s", dp[i][j], (j==b.size()?"\n":""));

        return dp[a.size()][b.size()] == a.size();
    }
    
    bool followUp(string &a, string &b)
    {
        int i=0, j=0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j])
                i++;
            j++;
        }
        return i == a.size();
    }
    
    bool isSubsequence(string s, string t)
    {
        return followUp(s, t);
    }
};

int main()
{
    cout << Solution{}.isSubsequence("axc", "ahbgdc") << '\n';
}