/*
 * Leetcode Easy 1614. Maximum Nesting Depth of the Parentheses
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
    int maxDepth(string s)
    {
        int l = 0;
        int m = INT_MIN;
        char mc;
        for(char c : s)
        {
            if(c == '(')
            {
                l++;
                m = max(m, l);
            }
            else if(c == ')')
            {
                l--;
            }
        }
        return max(m, 0);
    }
};

int main()
{
    // skip
}