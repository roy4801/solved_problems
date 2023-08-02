/*
 * Leetcode Medium 46. Permutations
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
    int n, k;
    vector<int> nums, cur;
    vector<bool> vis;
    vector<vector<int>> ans;
    void solve(int cnt)
    {
        if(cnt == n)
        {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                cur.push_back(nums[i]);
                cnt++;

                solve(cnt);

                vis[i] = 0;
                cur.pop_back();
                cnt--;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        n = nums.size();
        this->nums = nums;
        ans.clear();
        vis.resize(n);
        cur.reserve(n);
        //
        solve(0);
        return ans;
    }
};

int main()
{
    // skip
}
