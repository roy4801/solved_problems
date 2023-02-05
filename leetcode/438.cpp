/*
 * Leetcode Medium 438. Find All Anagrams in a String
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

class Solution {
public:
    int A[26], B[26];
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();

        if(m > n)
            return ans;

        for(int i = 0; i < m; i++)
        {
            A[s[i]-'a']++;
            B[p[i]-'a']++;
        }

        int i;
        for(i = 0; i < n - m; i++)
        {
            if(equal(A, A+26, B))
                ans.push_back(i);

            int l = s[i]-'a';
            int r = s[i+m]-'a';
            
            A[r]++;
            A[l]--;
        }

        if(equal(A, A+26, B))
            ans.push_back(i);

        return ans;
    }
};

int main()
{
    vector<pair<string, string>> in = {
        {"aaaaaaaaaa", "aaaaaaaaaaaaa"},
        {"cbaebabacd", "abc"},
        {"abab", "ab"},
        {"abaabbbabaabaaaabbbababab", "ab"},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.findAnagrams(i.X, i.Y));
    }
}