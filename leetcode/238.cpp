/*
 * Leetcode Medium 238. Product of Array Except Self
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
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int p = 1;

        int z = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                z++;
                continue;
            }
            p *= nums[i];
        }

        if(z >= 2)
            return ans;
        
        for(int i = 0; i < n; i++)
        {
            if(z)
            {
                ans[i] = nums[i] == 0 ? p : 0;
            }
            else
            {
                ans[i] = p / nums[i];
            }
        }
        return ans;
    }
};

int main()
{
	// skip
}