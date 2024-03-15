/*
 * Leetcode Medium 238. Product of Array Except Self
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
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> v(n);

        int z = 0;
        for(int i = 0; i < n; i++)
            if(nums[i] == 0)
                z++;

        int p = 1;
        for(int i = 0; i < n; i++)
            if(z == 1 && nums[i] != 0 || z != 1)
            p *= nums[i];

        for(int i = 0; i < n; i++)
            if(z == 1)
                v[i] = nums[i] == 0 ? p : 0;
            else
                v[i] = nums[i] ? p / nums[i] : p;
        return v;
    }
};

int main()
{
    // skip
}
