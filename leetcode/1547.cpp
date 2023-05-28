/*
 * Leetcode Hard 1547. Minimum Cost to Cut a Stick
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution {
public:
    vector<vector<int>> memo;
    vector<int> c;
    int solve(int l, int r)
    {
        if(memo[l][r] != -1)
            return memo[l][r];

        if(l+1 == r)
            return 0;

        int ans = INT_MAX;
        for(int i = l+1; i <= r-1; i++)
        {
            int left = solve(l, i);
            int right = solve(i, r);
            int cur = c[r] - c[l];
            int cost = left+right+cur;
            
            ans = min(ans, cost);
        }

        return (memo[l][r] = ans);
    }

    int minCost(int n, vector<int>& c)
    {
        sort(c.begin(), c.end());
        c.insert(c.begin(), 0);
        c.insert(c.end(), n);

        this->c = c;
        memo.resize(c.size(), vector<int>(c.size(), -1));

        int ans = solve(0, c.size()-1);
        return ans;
    }
};

int main()
{
    using InputType=pair<int, vector<int>>;
    vector<InputType> in = {
        {7, {1,3,4,5}},
        {9, {5,6,1,4,2}},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.minCost(i.X, i.Y));
    }
}
