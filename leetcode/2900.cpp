/*
 * Leetcode Easy 2900. Longest Unequal Adjacent Groups Subsequence I
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

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        int n = words.size();
        vector<string> ans;

        int cur;
        for(int i = 0; i < n; i++)
        {
            if(cur != groups[i])
            {
                cur = groups[i];
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
