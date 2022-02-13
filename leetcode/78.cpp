/*
 * Leetcode Medium 78. Subsets
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums)
    {
        int siz = nums.size();

        for(int i = 0; i < (int)pow(2, siz); i++)
        {
            bitset<15> flag(i);
            vector<int> tmp;

            for(int j = 0; j < nums.size(); j++)
            {
                if(flag[j])
                    tmp.push_back(nums[j]);
            }

            ans.push_back(tmp);
        }
        
        // DBG(ans);

        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3};
    Solution{}.subsets(v);
}