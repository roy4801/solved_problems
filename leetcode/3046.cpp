/*
 * Leetcode Easy 3046. Split the Array
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
    bool isPossibleToSplit(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i : nums)
            m[i]++;
        for(auto [num, cnt] : m)
        {
            if(cnt >= 3)
                return 0;
        }
        return 1;
    }
};

int main()
{
    // skip
}