/*
 * Leetcode Medium 1814. Count Nice Pairs in an Array
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

const int mod = 1e9+7;
class Solution {
public:
    int rev(int n)
    {
        int r = 0;
        while(n)
        {
            r *= 10;
            r += n % 10;
            n /= 10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums)
    {
        int n = nums.size();

        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        // => nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            int r = rev(nums[i]);
            nums[i] -= r;
        }

        // 遍歷 [0, n) 統計 nums[i] 出現次數(=m[nums[i]])
        // 每次往右的數字 nums[i] 就代表能組出的 pair 又多了 m[nums[i]] 個 (從 0 到 i-1 出現了幾個 nums[i])
        // 接著更新 nums[i] 出現次數
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += m[nums[i]];
            ans %= mod;
            m[nums[i]]++;
        }

        return ans;
    }
};

int main()
{

}