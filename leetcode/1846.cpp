/*
 * Leetcode Medium 1846. Maximum Element After Decreasing and Rearranging
 * author: roy4801
 * (C++)
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
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = 0;
        int tar = 1;
        int off = 0;
        while(1)
        {
            auto it = lower_bound(arr.begin()+off, arr.end(), tar);
            if(it != arr.end())
            {
                off = it - arr.begin();
                off += 1;
                tar++;
                ans++;
            }
            else
                break;
        }

        return ans;
    }
};

int main()
{
    // skip
}
