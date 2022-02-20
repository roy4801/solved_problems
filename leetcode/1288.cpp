/*
 * Leetcode Medium 1288. Maximum Subarray Sum with One Deletion
 * author: roy4801
 * AC(C++) 28ms 11.MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>>& v)
    {
        sort(v.begin(), v.end(), [](auto &lhs, auto &rhs){
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });

        // DBG(v);

        int ans = v.size();
        int ml = INT_MAX, mr = INT_MIN;
        int l, r;
        for(auto &p : v)
        {
            l = p[0], r = p[1];

            // printf("l=%d r=%d | ml=%d mr=%d\n", l, r, ml, mr);

            if(ml != INT_MAX && mr != INT_MIN)
            {
                if(ml <= l && r <= mr)
                    ans--;
            }

            ml = min(ml, l);
            mr = max(mr, r);
        }

        return ans;
    }
};

int main()
{
    // vector<vector<int>> v = {{1,4},{3,6},{2,8}};
    // vector<vector<int>> v = {{1, 4}, {2, 3}};
    vector<vector<int>> v = {{1, 2}, {1, 4}, {3, 4}};
    cout << Solution{}.removeCoveredIntervals(v) << '\n';
}