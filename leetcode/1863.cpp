/*
 * Leetcode Easy 1863. Sum of All Subset XOR Totals
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
    int subsetXORSum(vector<int>& nums)
    {
        int ans = 0;
        int n = nums.size();
        int upper = pow(2,n)-1;

        for(int i = 1; i <= upper; i++)
        {
            bitset<20> vis(i);

            int tmp = 0;
            for(int j = 0; j < n; j++)
                if(vis[j])
                    tmp ^= nums[j];
            ans += tmp;
        }

        return ans;
    }
};

int main()
{
    // skip
}
