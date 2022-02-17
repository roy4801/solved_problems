/*
 * Leetcode Medium 39. Combination Sum
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
    unordered_set<string> m;

    void bt(int sum, int target, vector<int> &nums, vector<int> v)
    {
        if(sum == target)
        {
            sort(v.begin(), v.end());
            string k;
            for(int i : v)
                k += to_string(i);
            if(!m.count(k))
            {
                m.insert(k);
                ans.push_back(v);
            }

            return;
        }

        for(int i : nums)
        {
            if(sum + i <= target)
            {
                vector<int> nv = v;
                nv.push_back(i);
                bt(sum+i, target, nums, nv);
                nv.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        bt(0, target, candidates, {});
        return ans;
    }
};

int main()
{
    vector<int> v = {2, 3, 6, 7};
    auto res = Solution{}.combinationSum(v, 7);
    DBG(res);
}