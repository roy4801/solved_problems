/*
 * Leetcode Easy 3065. Minimum Operations to Exceed Threshold Value I
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
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            if(nums[i] < k)
                ans++;
        return ans;
    }
};

int main()
{
    // skip
}