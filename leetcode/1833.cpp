/*
 * Leetcode Medium 1833. Maximum Ice Cream Bars
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
    int maxIceCream(vector<int>& N, int M) {
        int ans = 0;
        sort(N.begin(), N.end());
        for(int i : N)
        {
            if(M >= i)
            {
                M -= i;
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<pair<vector<int>,int>> in = {
        {{1,3,2,4,1}, 7},
        {{10,6,8,7,7,8}, 5},
        {{1,6,3,1,2,5}, 20},
    };
    for(auto &i : in)
    {
        auto &&[n, m] = tie(i.first, i.second);
        DBG(Solution{}.maxIceCream(n, m));
    }
}