/*
 * Leetcode Easy 1913. Maximum Product Difference Between Two Pairs
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
    int maxProductDifference(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return *nums.rbegin() * *(nums.rbegin()+1) -
               *nums.begin() * *(nums.begin()+1);
    }
};

int main()
{
    // skip
}
