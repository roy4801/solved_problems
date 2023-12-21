/*
 * Leetcode Medium 1637. Widest Vertical Area Between Two Points Containing No Points
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
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        int n = points.size();
        sort(points.begin(), points.end(), [](vector<int>& l, vector<int>& r){
            return l[0] < r[0];
        });

        int ans = INT_MIN;
        for(int i = 1; i < n; i++)
            ans = max(ans, points[i][0]-points[i-1][0]);
        return ans;
    }
};

int main()
{
    // skip
}
