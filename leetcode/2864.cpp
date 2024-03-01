/*
 * Leetcode Easy 2864. Maximum Odd Binary Number
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
    string maximumOddBinaryNumber(string s)
    {
        int one = 0;
        int n = s.size();
        for(char c : s)
            if(c == '1')
                one++;
        string ans(n, '0');
        if(one)
        {
            ans[n-1] = '1';
            one--;
        }
        for(int i = 0; i < one; i++)
            ans[i] = '1';
        return ans;
    }
};

int main()
{
    // skip
}