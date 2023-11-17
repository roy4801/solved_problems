/*
 * Leetcode Medium 1877. Minimize Maximum Pair Sum in Array
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
    int minPairSum(vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/2; i++)
        {
            ans = max(ans, nums[i]+nums[n-1-i]);
        }
        return ans;
    }
};

int main()
{
    // skip
}
