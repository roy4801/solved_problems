/*
 * Leetcode Easy 2194. Cells in a Range on an Excel Sheet
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        vector<string> ans;
        string tmp;
        int a = s[0]-'A', b = s[3]-'A';
        int av = s[1]-'0', bv = s[4]-'0';

        for(int i = a; i <= b; i++)
            for(int j = av; j <= bv; j++)
            {
                tmp += 'A' + i;
                tmp += '0' + j;
                ans.PB(tmp);
                tmp = "";
            }

        return ans;
    }
};

int main()
{
    // auto x = Solution{}.cellsInRange("K1:L2");
    auto x = Solution{}.cellsInRange("A1:F1");
    DBG(x);
}