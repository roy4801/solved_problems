/*
 * Leetcode Medium 2391. Minimum Amount of Time to Collect Garbage
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
    int garbageCollection(vector<string>& g, vector<int>& t)
    {
        int n = g.size();
        vector<int> v[3];

        // prefix sum for t[i] = t[0]+..+t[i]
        for(int i = 1; i < n-1; i++)
            t[i] += t[i-1];

        for(int j = 0; j < n; j++)
        {
            vector<int> tmp(3);
            for(int k = 0; k < g[j].size(); k++)
            {
                if(g[j][k] == 'M') tmp[0]++;
                else if(g[j][k] == 'P') tmp[1]++;
                else if(g[j][k] == 'G') tmp[2]++;
            }

            for(int i = 0; i < 3; i++)
                v[i].push_back(tmp[i]);
        }

        int ans = 0;
        for(int i = 0; i < 3; i++)
        {
            int k = -1; // rightmost idx which value != 0
            for(int j = 0; j < n; j++)
            {
                ans += v[i][j];
                if(v[i][j])
                    k = j;
            }
            
            if(k >= 1)
                ans += t[k-1]; // t[i] = t[0]+..+t[i]
        }

        return ans;
    }
};

int main()
{
    // skip
}