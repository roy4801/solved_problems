/*
 * Leetcode Easy 350. Intersection of Two Arrays II
 * author: roy4801
 * (C++)
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
    vector<int> intersect(vector<int>& a, vector<int>& b)
    {
        vector<int> ans;
        int n = a.size(), m = b.size();
        int an[1005] = {0}, bn[1005] = {0};

        for(int i = 0; i < n; i++)
            an[a[i]]++;
        for(int i = 0; i < m; i++)
            bn[b[i]]++;

        for(int i = 0; i <= 1000; i++)
        {
            int siz = min(an[i], bn[i]);
            for(int j = 0; j < siz; j++)
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    // skip
}