/*
 * Leetcode Medium 45. Jump Game II
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#define PRINT_INDEX false
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define INF 0x3f3f3f3f

using P=pair<int,int>;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n+5];
        memset(dp, 0, sizeof(dp));

        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--)
        {
            int tmp = INF;
            for(int j = i+1; j <= i+nums[i] && j < n; j++)
            {
                tmp = min(tmp, dp[j]+1);
            }
            dp[i] = tmp;
        }

        DBGN(dp, n);

        return dp[0];
    }
};

// 2 3 1 1 4
//         0
//       1 0
//     2 1 0
//   1 2 1 0  (3, 2, 1)
// 2 1 2 1 0  (2, 3)

int main()
{
    vector<vector<int>> in = {
        {2,3,1,1,4},
        {2,3,0,1,4},
        {2,9,6,5,7,0,7,2,7,9,3,2,2,5,7,8,1,6,6,6,3,5,2,2,6,3},
        {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.jump(i));
    }
}