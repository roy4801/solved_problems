/*
 * Leetcode Easy 2108. Find First Palindromic String in the Array
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
    bool isPalindrome(string& s)
    {
        int n = s.size();
        int i = 0, j = n-1;
        for(; i <= n/2 && j >= n/2; i++, j--)
            if(s[i] != s[j])
                return 0;
        return 1;
    }
    string firstPalindrome(vector<string>& words)
    {
        for(auto& s : words)
            if(isPalindrome(s))
                return s;
        return "";
    }
};

int main()
{
    // skip
}