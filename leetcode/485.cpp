/*
 * Leetcode Easy 485. Max Consecutive Ones
 * author: roy4801
 * AC(C++) 36ms 36.2MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int l = INT_MIN, n = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                n++;
            else
                n = 0;
            l = max(l, n);
        }
        return l;
    }
};

int main()
{
    vector<int> v = {1,1,0,1,1,1};
    cout << Solution{}.findMaxConsecutiveOnes(v) << '\n';
}