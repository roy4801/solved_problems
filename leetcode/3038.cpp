/*
 * Leetcode Easy 3038. Maximum Number of Operations With the Same Score I
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
    int maxOperations(vector<int>& nums)
    {
        int ans = 1;
        int n = nums.size();
        int m = nums[0] + nums[1];
        for(int i = 2; i < n; )
        {
            if(nums[i] + nums[i+1] == m)
            {
                ans++;
                i += 2;
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{
    // skip
}