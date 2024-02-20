/*
 * Leetcode Easy 268. Missing Number
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
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        unordered_set<int> s;
        for(int i : nums)
            s.insert(i);
        for(int i = 0; i <= n; i++)
            if(!s.count(i))
                return i;
        return -1;
    }
};

int main()
{
    // skip
}
