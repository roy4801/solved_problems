/*
 * Leetcode Medium 3634. Minimum Removals to Balance Array
 * author: roy4801
 * (C++)
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

using LL = long long;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1)
            return 0;
        
        int len = INT_MIN;
        int i = 0;
        for(int j = 0; j < n; j++)
        {
            while((LL)nums[j] > (LL)nums[i] * (LL)k)
            {
                i++;
            }
            len = max(len, j-i+1);
        }
        
        return n - len;
    }
};

int main()
{
    // skip
}
