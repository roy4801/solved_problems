/*
 * Leetcode Easy 1790. Check if One String Swap Can Make Strings Equal
 * author: roy4801
 * (C++) 0.012 6.2MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"
class Solution
{
public:
    bool areAlmostEqual(string a, string b)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                if (a == b)
                    return true;
                swap(a[i], a[j]);
                if (a == b)
                    return true;
                swap(a[i], a[j]);
            }
        return false;
    }
};

int main()
{
    cout << Solution{}.areAlmostEqual("bank", "kanb") << '\n';
}