/*
 * Leetcode Easy 1422. Maximum Score After Splitting a String
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
    int maxScore(string s)
    {
        int n = s.size();
        vector<int> z(n), o(n); // zeros, ones
        for(int i = 0; i < n; i++)
        {
            z[i] = (i-1>=0?z[i-1]:0) + (s[i] == '0');
            o[i] = (i-1>=0?o[i-1]:0) + (s[i] == '1');
        }

        auto calc = [&](auto& v, int a, int b)
        {
            return v[b] - (a-1 >= 0 ? v[a-1] : 0);
        };

        int ans = INT_MIN;
        for(int i = 0; i < n-1; i++)
            ans = max(ans, calc(z, 0, i)+calc(o, i+1, n-1));
        return ans;
    }
};

int main()
{
    // skip
}
