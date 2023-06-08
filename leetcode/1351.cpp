/*
 * Leetcode Medium 1351. Count Negative Numbers in a Sorted Matrix
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

// O(n^2logn)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            sort(grid[i].begin(), grid[i].end());
            auto it = lower_bound(grid[i].begin(), grid[i].end(), 0);
            ans += it - grid[i].begin();
        }

        return ans;
    }
};

// O(nlogn)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            auto it = upper_bound(grid[i].begin(), grid[i].end(), 0, greater<int>());
            int dis = it - grid[i].begin();
            ans += (m - dis);
        }

        return ans;
    }
};

int main()
{
    // skip
}
