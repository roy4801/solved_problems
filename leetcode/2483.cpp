/*
 * Leetcode Medium 2483. Minimum Penalty for a Shop
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
    int bestClosingTime(string c)
    {
        int siz = c.size();
        vector<int> y(siz), n(siz);

        for(int i = 0; i < siz; i++)
        {
            bool ok = c[i] == 'N';
            n[i] = i == 0 ? ok : n[i-1] + ok;
        }

        for(int i = siz-1; i >= 0; i--)
        {
            bool ok = c[i] == 'Y';
            y[i] = i == siz-1 ? ok : y[i+1] + ok;
        }

        int ans = INT_MAX;
        int ansH = 0;
        for(int i = 0; i < siz+1; i++)
        {
            int tmp = 0;
            tmp += i < siz ? y[i] : 0;
            tmp += i > 0 ? n[i-1] : 0;
            if(tmp < ans)
            {
                ans = tmp;
                ansH = i;
            }
        }

        return ansH;
    }
};

int main()
{
    // skip
}
