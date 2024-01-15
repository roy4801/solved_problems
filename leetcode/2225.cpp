/*
 * Leetcode Medium 2225. Find Players With Zero or One Losses
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
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        vector<vector<int>> ans(2);
        int n = matches.size();
        unordered_map<int, int> wm, lm;

        for(auto i  : matches)
        {
            auto [w, l] = tie(i[0], i[1]);
            wm[w]++;
            lm[l]++;
        }

        for(auto [i, cnt] : wm)
        {
            if(!lm.count(i))
                ans[0].push_back(i);
        }
        for(auto [i, cnt] : lm)
        {
            if(cnt == 1)
                ans[1].push_back(i);
        }
        for(int i = 0; i < 2; i++)
            sort(ans[i].begin(), ans[i].end());
        return ans;
    }
};

int main()
{
    // skip
}
