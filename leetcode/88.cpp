/*
 * Leetcode Easy 88. Merge Sorted Array
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    void merge(vector<int> &a, int m, vector<int> &b, int n)
    {
        solve2(a, m, b, n);
    }

    void solve1(vector<int> &a, int m, vector<int> &b, int n)
    {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < m && j < n)
        {
            if (a[i] > b[j])
                ans.push_back(b[j]), j++;
            else
                ans.push_back(a[i]), i++;
        }
        // only one while will be executed in the end
        while (i < m)
            ans.push_back(a[i]), i++;
        while (j < n)
            ans.push_back(b[j]), j++;

        print(ans);
    }

    // in-place
    void solve2(vector<int> &a, int m, vector<int> &b, int n)
    {
        int i = m-1, j = n-1, k = m+n-1;
        while (i >= 0 && j >= 0)
        {
            if (a[i] > b[j])
                a[k] = a[i], i--;
            else
                a[k] = b[j], j--;
            k--;
        }
        while (i >= 0)
            a[k] = a[i], i--, k--;
        while (j >= 0)
            a[k] = b[j], j--, k--;
    }
};

int main()
{
    vector<int> a{1,2,3,0,0,0}, b{2,5,6};
    Solution{}.merge(a, 3, b, 3);
    print(a);
}