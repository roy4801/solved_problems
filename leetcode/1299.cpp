/*
 * Leetcode Medium 1299. K-Concatenation Maximum Sum
 * author: roy4801
 * AC(C++) 0.020
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    vector<int> replaceElements(vector<int>& n) {
        int cur = -1;
        for(int i = n.size()-1; i >= 0; i--)
        {
            int tmp = cur;
            if(n[i] > cur)
                cur = n[i];
            n[i] = tmp;
        }
        return n;
    }
};

int main()
{
    vector<int> v = {17,18,5,4,6,1};
    DBG(Solution{}.replaceElements(v));
}