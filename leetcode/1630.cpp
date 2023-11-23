/*
 * Leetcode Medium 1630. Arithmetic Subarrays
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
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& L, vector<int>& R)
    {
        int n = nums.size(), m = L.size();
        vector<bool> ans(m);

        for(int i = 0; i < m; i++)
        {
            int l = L[i], r = R[i];
            vector<int> v(nums.begin()+l, nums.begin()+r+1);

            sort(v.begin(), v.end());

            unordered_set<int> s;
            for(int j = 1; j < v.size(); j++)
            {
                int diff = v[j]-v[j-1];
                s.insert(diff);
            }

            ans[i] = s.size() == 1;
        }

        return ans;
    }
};

int main()
{
    // skip
}
