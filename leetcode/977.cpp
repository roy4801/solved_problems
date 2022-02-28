/*
 * Leetcode Easy 977. Squares of a Sorted Array
 * author: roy4801
 * AC(C++) 32ms 26.9MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

class Solution {
public:
    vector<int> sortedSquares(vector<int>& n)
    {
        vector<int> ans;
        int neg = -1;
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] < 0)
                neg = i;
            n[i] *= n[i];
        }
        // printf("> %d\n", neg);
        int pos = neg + 1;
        while (pos < n.size() && neg >= 0)
        {
            if (n[pos] > n[neg])
                ans.push_back(n[neg]), neg--;
            else
                ans.push_back(n[pos]), pos++;
        }
        while(pos < n.size())
            ans.push_back(n[pos]), pos++;
        while(neg >= 0)
            ans.push_back(n[neg]), neg--;
        if(ans.empty())
            ans = n;
        return ans;
    }
};

int main()
{
    vector<int> v = {-7,-3,2,3,11};
    v = Solution{}.sortedSquares(v);
    DBG(v);
}