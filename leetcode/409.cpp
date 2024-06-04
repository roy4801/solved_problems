/*
 * Leetcode Easy 409. Longest Palindrome
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
    int longestPalindrome(string s)
    {
        int ans = 0;
        bool f = 0;

        unordered_map<char,int> ch;
        for(char c : s)
            ch[c]++;

        for(char c : {'a', 'A'})
            for(int i = 0; i < 26; i++)
            {
                if(ch[c+i] > 0)
                {
                    if(ch[c+i] % 2 == 0)
                    {
                        ans += ch[c+i];
                    }
                    else
                    {
                        ans += ch[c+i]-1;
                        f = 1;
                    }
                }
            }
        if(f)
            ans++;
        return ans;
    }
};

int main()
{
    // skip
}