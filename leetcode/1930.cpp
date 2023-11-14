/*
 * Leetcode Medium 1930. Unique Length-3 Palindromic Subsequences
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

#define X first
#define Y second
using P=pair<int,int>;
class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        // Init
        int ans = 0;
        int n = s.size();
        P cnt[26]; // (left most idx, right most idx)
        for(int i = 0; i < 26; i++)
        {
            cnt[i].X = INT_MAX;
            cnt[i].Y = INT_MIN;
        }
        
        // Find left, right most
        for(int i = 0; i < n; i++)
        {
            auto& c = cnt[s[i]-'a'];
            c.X = min(c.X, i);
            c.Y = max(c.Y, i);
        }

        // Calc the number of unique chars between [a+1, b-1]
        // = how many unique palindrome are s[a]?s[b]
        for(int i = 0; i < 26; i++)
        {
            if(cnt[i].X == INT_MAX)
                continue;

            int a = cnt[i].X, b = cnt[i].Y;
            set<char> m;
            for(int j = a+1; j <= b-1; j++)
                m.insert(s[j]);
            ans += m.size();
        }
        
        return ans;
    }
};

int main()
{
    // skip
}