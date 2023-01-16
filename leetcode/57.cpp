/*
 * Leetcode Medium 57. Insert Interval
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

#define N 10000
class Solution {
public:
    bool overlap[N+5];
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto IsOverlap = [](vector<int>& a, vector<int>& b)
        {
            return a[1] >= b[0] && b[1] >= a[0];
        };

        if(intervals.empty()) return {newInterval};

        int n = intervals.size();
        int minX = INT_MAX, maxX = INT_MIN;
        int k = 0;
        for(auto& i : intervals)
        {
            if(IsOverlap(i, newInterval))
            {
                overlap[k] = true;
                //printf("%d ", k);
                minX = min(minX, i[0]);
                minX = min(minX, newInterval[0]);
                maxX = max(maxX, i[1]);
                maxX = max(maxX, newInterval[1]);
            }
            k++;
        }

        vector<vector<int>> ans;
        bool added = false;
        for(int i = 0; i < n; i++)
        {
            if(!overlap[i])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                if(!added)
                {
                    ans.push_back({minX, maxX});
                }
                added = true;
            }
        }

        if(!added)
        {
            ans.push_back({newInterval});
        }

        sort(ans.begin(), ans.end(), [](auto &lhs, auto &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
        });

        // printf("%d %d\n", minX, maxX);
        return ans;
    }
};

int main()
{
    using Input=pair<vector<vector<int>>, vector<int>>;
    vector<Input> in = {
        { {{1,3}, {6,9}}, {2, 5} },
        { {{1,2},{3,5},{6,7},{8,10},{12,16}}, {4,8} },
        { {}, {5,7} },
        { {{1,5}}, {6,8} },
        { {{1,3}}, {0,0} },
    };
    for(auto &i : in)
    {
        DBG(Solution{}.insert(i.X, i.Y));
    }
}