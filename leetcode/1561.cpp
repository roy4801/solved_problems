/*
 * Leetcode Medium 1561. Maximum Number of Coins You Can Get
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
    int maxCoins(vector<int>& v)
    {
        int ans = 0;
        int n = v.size();
        sort(v.begin(), v.end());

        int i = 0, cnt = 0;
        for(int j = n-1; j >= i; j--)
        {
            cnt++;
            if(cnt == 2)
            {
                ans += v[j];
                i++;
                cnt = 0;
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
