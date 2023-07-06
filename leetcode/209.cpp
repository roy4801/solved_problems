/*
 * Leetcode Medium 209. Minimum Size Subarray Sum
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
    int minSubArrayLen(int t, vector<int>& v)
    {
        int n = v.size();
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MAX;

        auto check = [&]() {
            if(sum >= t)
                ans = min(ans, j-i+1);
        };

        while(j < n)
        {
            sum += v[j];

            check();

            while(sum-v[i] >= t)
            {
                sum -= v[i++];
                check();
            }

            j++;
        }
        j--;

        check();
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    // skip
}
