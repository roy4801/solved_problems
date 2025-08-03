/*
 * Leetcode Easy 3637. Trionic Array I
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
    int n;
    vector<int> nums;
    bool ok(int p, int q)
    {
        // Check [0, p] is strictly increasing
        for(int i = 1; i <= p; i++)
            if(nums[i-1] >= nums[i])
                return 0;
        // Check [p+1, q] is strictly decreasing
        for(int i = p+1; i <= q; i++)
            if(nums[i-1] <= nums[i])
                return 0;
        // Check [q+1, n-1] is strictly increasing
        for(int i = q+1; i <= n-1; i++)
            if(nums[i-1] >= nums[i])
                return 0;
        return 1;
    }
    bool isTrionic(vector<int>& _nums)
    {
        nums = _nums;
        n = nums.size();
        // 0 < p < q < n−1
        for(int i = 1; i < n-2; i++)
            for(int j = i+1; j < n-1; j++)
                if(ok(i, j))
                    return 1;
        return 0;
    }
};

int main()
{
    // skip
}