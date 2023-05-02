/*
 * Leetcode Easy 1822. Sign of the Product of an Array 
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
    int arraySign(vector<int>& nums)
    {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < 0) cnt++;
            else if(nums[i] == 0) return 0;
        }
        return cnt % 2 != 0 ? -1 : 1;
    }
};

int main()
{
    // skip
}
