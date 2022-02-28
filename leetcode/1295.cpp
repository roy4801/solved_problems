/*
 * Leetcode Medium 1295. Minimum Garden Perimeter to Collect Enough Apples
 * author: roy4801
 * AC(C++) 4ms 9.8MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

int digi(int n)
{
    int d = 0;
    while(n)
    {
        n /= 10;
        d++;
    }
    return d;
}

class Solution {
public:
    int findNumbers(vector<int>& nums)
    {
        int ans = 0;
        for(auto i : nums)
        {
            if(digi(i) % 2 == 0)
                ans++;
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {12,345,2,6,7896};
    cout << Solution{}.findNumbers(v) << '\n';
}