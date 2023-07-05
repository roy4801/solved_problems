/*
 * Leetcode Medium 2305. Fair Distribution of Cookies
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
    int solve(int i, vector<int> &c, int k, vector<int> &s)
    {
        if(i >= c.size())
        {
            return *max_element(s.begin(), s.end());
        }

        int ans = INT_MAX;
        for(int j = 0; j < k; j++)
        {
            s[j] += c[i];
            ans = min(ans, solve(i+1, c, k, s));
            s[j] -= c[i];
        }

        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k)
    {
        vector<int> s(k);
        // s[i] = k 人當前餅乾數量
        return solve(0, cookies, k, s);
    }
};

int main()
{
    // skip
}
