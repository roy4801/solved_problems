/*
 * Leetcode Easy 459. Repeated Substring Pattern
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
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        if(n == 1) return 0;
        // 子字串長度
        for(int i = 1; i <= n/2; i++)
        {
            // 不整除 s 長度一定不是 pattern
            if(n % i != 0)
                continue;
            // 看長度 i 的子字串是不是都一樣
            string sub;
            int ok = 1;
            for(int j = 0; j < n; j += i)
            {
                if(j+i > n)
                    continue;

                if(j == 0)
                    sub = s.substr(j, i);
                else
                {
                    if(sub == s.substr(j, i))
                        ok++;
                }
            }
            if(ok == n/i)
                return 1;
        }
        return 0;
    }
};
int main()
{
    /*
    "abab"
    "aba"
    "abcabcabcabc"
    "aabaaba"
    "a"
    "babbabbabbabbab"
    */
    // skip
}