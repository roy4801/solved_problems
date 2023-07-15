/*
 * Leetcode Medium 1218. Lowest Common Ancestor of Deepest Leaves
 * author: roy4801
 * (C++)
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

#define M 10000
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff)
    {
        int n = arr.size();
        for(int i = 0; i < n; i++)
            arr[i] += M;
        vector<int> dp(3*M+5);

        for(int i = 0; i < n; i++)
        {
            if(arr[i]-diff >= 0)
                dp[arr[i]] = 1 + dp[arr[i]-diff];
            else
                dp[arr[i]] = 1;
        }

        int ans = 0;
        for(int i = 0; i <= 2*M+1; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    // skip
}
