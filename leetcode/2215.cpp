/*
 * Leetcode Easy 2215. Find the Difference of Two Arrays
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution {
public:
    int m[2005];
    void clear() { for(int i = 0; i <= 2000; i++) m[i] = 0; }
    bool check(int n)
    {
        return m[n+1000];
    }
    void add(int n) { m[n+1000]++; }

    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b)
    {
        int n = a.size();
        vector<vector<int>> ans(2, vector<int>{});

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        auto it = unique(a.begin(), a.end());
        a.erase(it, a.end());
        it = unique(b.begin(), b.end());
        b.erase(it, b.end());

        clear();
        for(int i = 0; i < b.size(); i++)
            add(b[i]);
        for(int i = 0; i < a.size(); i++)
            if(!check(a[i]))
                ans[0].push_back(a[i]);

        clear();
        for(int i = 0; i < a.size(); i++)
            add(a[i]);
        for(int i = 0; i < b.size(); i++)
            if(!check(b[i]))
                ans[1].push_back(b[i]);

        return ans;
    }
};

int main()
{

}
