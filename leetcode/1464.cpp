/*
 * Leetcode Easy 1464. Maximum Product of Two Elements in an Array
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
    int maxProduct(vector<int>& nums)
    {
        int ans = INT_MIN;
        int n = nums.size();
        int a = 0, b = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > a)
            {
                b = a;
                a = nums[i];
            }
            else if(nums[i] > b)
            {
                b = nums[i];
            }
        }

        return (a-1)*(b-1);
    }
};

int main()
{
    // skip
}
