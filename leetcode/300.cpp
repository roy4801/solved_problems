/*
 * Leetcode Medium 300. Longest Increasing Subsequence
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
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> v;
        v.push_back(nums[0]);

        for(int i = 1; i < n; i++)
        {
            if(v.back() < nums[i])
            {
                v.push_back(nums[i]);
            }
            else
            {
                auto it = lower_bound(v.begin(), v.end(), nums[i]);
                *it = nums[i];
            }
        }
        return v.size();
    }
};

int main()
{
    // skip
}
