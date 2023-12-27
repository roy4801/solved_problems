/*
 * Leetcode Medium 1578. Minimum Time to Make Rope Colorful
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
    int minCost(string c, vector<int>& t)
    {
        int n = c.size();

        int ans = 0;
        int m = INT_MIN, sum = 0;
        int i = 0, j = i;
        while(j < n)
        {
            if(c[i] != c[j])
            {
                if(j-i+1 > 1)
                {
                    ans += sum - m;
                    sum = 0;
                    m = INT_MIN;
                }

                i = j;
                continue;
            }

            sum += t[j];
            m = max(m, t[j]);

            if(c[i] == c[j])
            {
                j++;
            }
        }

        if(j-i+1 > 1)
        {
            ans += sum - m;
            sum = 0;
            m = INT_MIN;
        }

        return ans;
    }
};

int main()
{
    // skip
}