/*
 * Leetcode Easy 88. Merge Sorted Array
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    void merge(vector<int> &a, int m, vector<int> &b, int n)
    {
        vector<int> ans;
        int i = 0, j = 0;

        while(i < m && j < n)
        {
            if(a[i] > b[j])
                ans.push_back(b[j]), j++;
            else
                ans.push_back(a[i]), i++;
        }
        // only one while will be executed in the end
        while(i < m)
            ans.push_back(a[i]), i++;
        while(j < n)
            ans.push_back(b[j]), j++;

        print(ans);
    }
};

int main()
{
    vector<int> a{1,2,3,0,0,0}, b{2,5,6};
    Solution{}.merge(a, 3, b, 2);
}