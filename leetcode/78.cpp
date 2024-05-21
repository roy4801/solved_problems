/*
 * Leetcode Medium 78. Subsets
 * author: roy4801
 * AC(C++) 0.007ms 7.3MB
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

class Solution2
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        auto solve = [&](vector<int> cur, int i, auto&& solve)
        {
            if(i == n)
            {
                ans.push_back(cur);
                return;
            }

            solve(cur, i+1, solve);
            cur.push_back(nums[i]);
            solve(cur, i+1, solve);
            cur.pop_back();
        };

        solve({}, 0, solve);
        return ans;
    }
};

class Solution3
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        int N = pow(2, n) - 1;
        vector<vector<int>> ans;
        for(int i = 0; i <= N; i++)
        {
            bitset<10> vis(i);
            vector<int> cur;
            for(int j = 0; j < n; j++)
                if(vis[j])
                    cur.push_back(nums[j]);
            ans.push_back(cur);
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3};
    Solution{}.subsets(v);
}
