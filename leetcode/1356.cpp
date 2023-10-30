/*
 * Leetcode Easy 356. Sort Integers by The Number of 1 Bits
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
    vector<int> sortByBits(vector<int>& arr)
    {
        vector<int> ans;
        vector<int> b[32];
        for(int n : arr)
            b[__popcount(n)].push_back(n);
        for(int i = 0; i < 32; i++)
            if(b[i].size())
                sort(b[i].begin(), b[i].end());
        for(int i = 0; i < 32; i++)
            if(b[i].size())
                ans.insert(ans.end(), b[i].begin(), b[i].end());
        return ans;
    }
};

class Solution2 {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), [](const int lhs, const int rhs) {
            return __popcount(lhs) == __popcount(rhs) ?
                        lhs < rhs :
                        __popcount(lhs) < __popcount(rhs);
        });
        return arr;
    }
};

inline int popcount(int n)
{
    int ans = 0;
    while(n)
    {
        n &= n-1;
        ans++;
    }
    return ans;
}
class Solution3 {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), [](const int lhs, const int rhs) {
            return popcount(lhs) == popcount(rhs) ?
                        lhs < rhs :
                        popcount(lhs) < popcount(rhs);
        });
        return arr;
    }
};

int main()
{
    // skip
}
