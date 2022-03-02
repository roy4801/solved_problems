/*
 * Leetcode Medium 435. Non-overlapping Intervals
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v)
    {
        sort(v.begin(), v.end(), [](auto &lhs, auto &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
        });
        
        if(v.size() <= 1)
            return 0;
        
        int ans = 0, r = v[0][1];
        for(int i = 1; i < v.size(); i++)
        {
            // Overlap
            if(r > v[i][0])
            {
                // 右界越小越好 (因為最後是要全部不重疊的)
                r = min(r, v[i][1]);
                // 重疊兩條要刪掉其中一條
                ans++;
            }
            else
            {
                r = v[i][1];
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    Solution{}.eraseOverlapIntervals(v);
}