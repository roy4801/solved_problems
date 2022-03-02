/*
 * Leetcode Medium 56. Merge Intervals
 * author: roy4801
 * AC(C++) 48ms 19.1MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& v)
    {
        vector<vector<int>> ans;

        if(v.size() <= 1) return v;

        // sort(v.begin(), v.end(), [](vector<int> &lhs, vector<int> &rhs) {
        //     return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
        // });

        int cur = 0, r = 1;

        while(cur < v.size() && r < v.size())
        {
            // printf("> %d %d\n", cur, r);
            if(v[cur][1] >= v[r][0])
            {
                // is not include
                if(v[cur][1] <= v[r][1])
                    v[cur][1] = v[r][1];
            }
            else
            {
                // puts("In");
                ans.push_back(v[cur]);
                cur = r;
            }
            r++;
        }

        ans.push_back(v[cur]);
        return ans;
    }
};

int main()
{
    // vector<vector<int>> v = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> v = {{1,4}, {2,3}};
    v = Solution{}.merge(v);
    DBG(v);
}