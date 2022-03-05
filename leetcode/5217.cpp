/*
 * Leetcode Medium 5217. Sort the Jumbled Numbers
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

class Solution
{
public:
    struct T
    {
        int val;
        int orig;

        T(int v, int p)
        {
            val = v;
            orig = p;
        }

        bool operator<(T &rhs)
        {
            return val < rhs.val;
        }
    };

    int convert(vector<int>& m, int v)
    {
        int ans = 0;
        vector<int> a;
        while(v)
        {
            a.PB(v % 10);
            v /= 10;
        }
        if(a.empty()) a.PB(0);
        // DBG(a);
        for(int i = a.size()-1; i >= 0; i--)
        {
            ans *= 10;
            ans += m[a[i]];
        }
        // printf("CVT %d\n", ans);
        return ans;
    }
    vector<int> sortJumbled(vector<int>& m, vector<int>& n)
    {
        vector<T> ans;
        for(int i : n)
        {
            int cvt = convert(m, i);
            // printf("%d -> %d\n", i, cvt);
            ans.push_back(T(cvt, i));
        }

        sort(ans.begin(), ans.end());

        vector<int> aa;
        for(int i = 0; i < ans.size(); i++)
            aa.PB(ans[i].orig);

        return aa;
    }
};

int main()
{
    // vector<int> m = {8,9,4,0,2,1,3,5,7,6};
    // vector<int> n = {991,338,38};
    // vector<int> m = {0,1,2,3,4,5,6,7,8,9};
    // vector<int> n = {789,456,123};
    vector<int> m = {9,8,7,6,5,4,3,2,1,0};
    vector<int> n = {0,1,2,3,4,5,6,7,8,9};

    auto ans = Solution{}.sortJumbled(m, n);
    DBG(ans);
}