/*
 * Leetcode Easy 1431. Kids With the Greatest Number of Candies
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
    vector<bool> kidsWithCandies(vector<int>& n, int a)
    {
        int max = *max_element(n.begin(), n.end());
        vector<bool> ans(n.size(), false);
        for(int i = 0; i < n.size(); i++)
        {
            if(n[i]+ a >= max)
            {
                ans[i] = true;
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}