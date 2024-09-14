/*
 * Leetcode Medium 2419. Longest Subarray With Maximum Bitwise AND
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
    int longestSubarray(vector<int>& nums)
    {
        vector<pair<int,int>> v;
        int cur = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i-1])
            {
                v.emplace_back(nums[i-1], cur);
                cur = 1;
            }
            else
                cur++;
        }
        v.emplace_back(nums[n-1], cur);

        sort(v.begin(), v.end());
        return v.back().second;
    }
};

int main()
{
    // skip
}