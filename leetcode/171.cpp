/*
 * Leetcode Easy 171. Excel Sheet Column Number
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

int pp(int a, int b)
{
    if(b == 0) return 1;
    else if(b == 1) return a;
    
    int h = b/2;
    int hv = pp(a,h);
    if(b % 2 != 0)
        return hv*hv*a;
    else
        return hv*hv;
}

class Solution {
public:
    int titleToNumber(string s)
    {   
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            ans += (s[i]-'A'+1) * pp(26, s.size()-1-i);
        }
        return ans;
    }
};


int main()
{
    cout << Solution{}.titleToNumber("AB") << '\n';
}