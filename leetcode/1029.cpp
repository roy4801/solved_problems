/*
 * Leetcode Medium 1029. Two City Scheduling
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

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>>& c)
    {
        sort(c.begin(), c.end(), [](auto &lhs, auto &rhs) {
            return lhs[0] - lhs[1] < rhs[0] - rhs[1];
        });
        
        int ans = 0, n = c.size() / 2;
        
        for(int i = 0; i < n; i++)
            ans += c[i][0];    
        for(int i = n; i < c.size(); i++)
            ans += c[i][1];
        
        return ans;
    }
};

int main()
{
    // skip
}