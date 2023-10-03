/*
 * Leetcode Easy 512. Number of Good Pairs
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
    int numIdenticalPairs(vector<int>& nums)
    {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] == nums[j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}
