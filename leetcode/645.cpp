/*
 * Leetcode Easy 645. Set Mismatch
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
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i : nums)
            m[i]++;

        vector<int> ans;
        for(int i = 1; i <= n; i++)
            if(m[i] >= 2)
                ans.push_back(i);
        for(int i = 1; i <= n; i++)
            if(m[i] <= 0)
                ans.push_back(i);

        return ans;
    }
};

int main()
{
    // skip
}
