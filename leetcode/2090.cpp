/*
 * Leetcode Medium 2090. K Radius Subarray Averages
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

using ll = long long;
class Solution {
public:
    vector<int> getAverages(vector<int>& v, int k)
    {
        int n = v.size();
        vector<ll> pre(n);

        ll acc = 0;
        for(int i = 0; i < n; i++)
        {
            acc += v[i];
            pre[i] = acc;
        }

        int r = k*2+1;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(i-k >= 0 && i+k < n)
            {
                ll num = pre[i+k]-pre[i-k]+v[i-k];
                ans.push_back(num / r);
            }
            else
                ans.push_back(-1);
        }
        return ans;
    }
};

int main()
{
    // skip
}
