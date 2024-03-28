/*
 * Leetcode Medium 2958. Length of Longest Subarray With at Most K Frequency
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
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int,int> cnt;

        int ans = INT_MIN;
        while(j < n)
        {
            cnt[nums[j]]++;
            while(cnt[nums[j]] > k)
            {
                cnt[nums[i]]--;
                i++;
            }

            if(cnt[nums[j]] <= k)
                ans = max(ans, j-i+1);

            j++;
        }
        return ans;
    }
};

int main()
{
    // skip
}
