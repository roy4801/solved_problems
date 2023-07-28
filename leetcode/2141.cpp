/*
 * Leetcode Hard 2141. Maximum Running Time of N Computers
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

using LL=long long;
class Solution {
public:
    LL maxRunTime(int n, vector<int>& batt)
    {
        int m = batt.size();
        auto ok = [&](LL t)
        {
            LL sum = 0;
            for(int i = 0; i < m; i++)
                sum += batt[i]>=t ? t : batt[i];
            return sum >= t * n;
        };

        sort(batt.begin(), batt.end());
        LL sum = accumulate(batt.begin(), batt.end(), 0LL);
        LL l = 0, r = sum+1;
        while(l < r)
        {
            LL mid = l + (r-l)/2;
            if(ok(mid))
                l = mid+1;
            else
                r = mid;
        }
        return l-1;
    }
};


int main()
{
    // skip
}