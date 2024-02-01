/*
 * Leetcode Medium 2966. Divide Array Into Arrays With Max Difference
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
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = INT_MAX;
        for(int i = 0; i < n; i += 3)
        {
            left = nums[i];
            for(int j = 1; j < 3; j++)
            {
                if(nums[i+j]-left > k)
                    return {};
            }

            ans.push_back({&nums[i], &nums[i+3]});
        }

        return ans;
    }
};

int main()
{
    // skip
}