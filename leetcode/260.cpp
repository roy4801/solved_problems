/*
 * Leetcode Medium 260. Single Number III
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
    vector<int> singleNumber(vector<int>& nums)
    {
        int n = nums.size();
        int x = 0;
        for(int i : nums)
            x ^= i;

        int a = 0, b = 0;
        for(int i = 0; i < 32; i++)
        {
            if(x & (1<<i))
            {
                for(int j : nums)
                {
                    if(j & (1<<i))
                        a ^= j;
                    else
                        b ^= j;
                }
                break;
            }
        }
        return {a, b};
    }
};

int main()
{
    // skip
}