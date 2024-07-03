/*
 * Leetcode Medium 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
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

// 懶得想 loop 方法&邊界，直接模擬  <== idiot
class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;

        sort(nums.begin(), nums.end());
        vector<bool> vis(n, 1);

        int ans = INT_MAX;
        int a = 3, b = 0;
        auto set = [&](bool flag) {
            for(int i = 0; i < a; i++)
                vis[i] = flag;
            for(int i = 0; i < b; i++)
                vis[n-1-i] = flag;
        };
        while(b <= 3)
        {
            set(0);
            
            int maxN = INT_MIN, minN = INT_MAX;
            for(int i = 0; i < n; i++)
                if(vis[i])
                {
                    maxN = max(maxN, nums[i]);
                    minN = min(minN, nums[i]);
                }
                
            ans = min(ans, maxN - minN);

            set(1);
            a--;
            b++;
        }
        return ans;
    }
};

class Solution2 {
public:
    int minDifference(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        for(int i = 0; i <= 3; i++)
            ans = min(ans, nums[n-1 - i] - nums[3 - i]);
            
        return ans;
    }
};

int main()
{
    // skip
}