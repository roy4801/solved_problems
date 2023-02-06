/*
 * Leetcode Easy 1470. Shuffle the Array
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

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[n+i]);
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // encode 10bit
        for(int i = n; i < 2*n; i++)
        {
            nums[i] = (nums[i]<<10) | nums[i-n];
        }

        const int mask = pow(2,10)-1;

        for(int i = 0, j = n; i < 2*n && j < 2*n; )
        {
            nums[i] = nums[j] & mask;
            nums[i+1] = nums[j] >> 10;
            j++;
            i += 2;
        }
        return nums;
    }
};

int main()
{
    // skip
}