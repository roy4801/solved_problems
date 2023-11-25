/*
 * Leetcode Medium 1685. Sum of Absolute Differences in a Sorted Array
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
    vector<int> getSumAbsoluteDifferences(vector<int>& v)
    {
        vector<int> ans;
        int n = v.size();

        // prefix sum
        vector<int> pre(n);
        for(int i = 0; i < n; i++)
            pre[i] = (i >= 1 ? pre[i-1]+v[i] : v[i]);
        // sum(a, b) = v[a]+...+v[b]
        auto sum = [&](int a, int b) {
            return pre[b] - (a-1 >= 0 ? pre[a-1] : 0);
        };

        for(int i = 0; i < n; i++)
        {
            int tmp = 0;
            tmp += v[i]*(i+1) - sum(0, i);
            tmp += sum(i, n-1) - (v[i]*(n-i));
            ans.push_back(tmp);
        }

        return ans;
    }
};

int main()
{
    // skip
}