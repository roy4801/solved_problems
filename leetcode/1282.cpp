/*
 * Leetcode Medium 1282. Group the People Given the Group Size They Belong To
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
    vector<vector<int>> groupThePeople(vector<int>& gs)
    {
        int n = gs.size();
        int siz = INT_MIN;
        // maximum group siz
        for(int i = 0; i < n; i++)
            siz = max(siz, gs[i]);
        // g[i] = collection of people who wants in group i
        vector<vector<int>> g(siz+1);
        for(int i = 0; i < n; i++)
            g[gs[i]].push_back(i);

        vector<vector<int>> ans;
        // group size
        for(int i = 1; i <= siz; i++)
        {
            // group
            for(int k = 0; k < g[i].size()/i; k++)
            {
                vector<int> tmp; // people
                for(int j = 0; j < i; j++)
                    tmp.push_back(g[i][k+j]);
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
