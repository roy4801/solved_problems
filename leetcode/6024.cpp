/*
 * Leetcode Easy 6024. Most Frequent Number Following Key In an Array
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back
#define MP make_pair

class Solution
{
public:
    map<int, int> m;
    int mostFrequent(vector<int>& n, int k)
    {
        for(int i = 0; i < n.size(); i++)
        {
            if(n[i] == k && i+1 < n.size())
            {
                m[n[i+1]]++;
            }
        }

        // DBG(m);

        vector<pair<int, int>> v;
        for(auto &&[i, j] : m)
        {
            v.PB(MP(j, i));
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());

        // DBG(v);

        return v.front().second;
    }
};

int main()
{
    // vector<int> v = {2, 1, 2, 1, 2, 3};
    vector<int> v = {1, 100, 200, 1, 100};
    int k = 1;

    cout << Solution{}.mostFrequent(v, k) << '\n';
}