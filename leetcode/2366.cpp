/*
 * Leetcode Hard 2366. Minimum Replacements to Sort the Array
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
    long long minimumReplacement(vector<int>& v)
    {
        int n = v.size();
        int i = n-2;
        LL ans = 0;
        while(i >= 0)
        {
            if(v[i] > v[i+1])
            {
                LL siz = v[i]/v[i+1] + (v[i]%v[i+1] != 0 ? 1 : 0);
                ans += siz-1;
                v[i] = v[i] / siz;
            }

            i--;
        }

        return ans;
    }
};

int main()
{
    // skip
}