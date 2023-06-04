/*
 * Leetcode Medium 1376. Time Needed to Inform All Employees
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
    int numOfMinutes(int n, int hid, vector<int>& m, vector<int>& time)
    {
        // build graph
        vector<vector<int>> G(n, vector<int>{});
        for(int i = 0; i < n; i++)
        {
            int p = m[i];
            // connect p -> i when p != -1
            if(p != -1)
                G[p].push_back(i);
        }

        // bfs starts from hid -> find maximum w
        int ans = INT_MIN;
        queue<arr<int, 2>> q; // (node idx, total time)
        q.push({hid, time[hid]});

        while(!q.empty())
        {
            auto [i, w] = q.front();
            q.pop();
            ans = max(ans, w);

            for(int j : G[i])
                q.push({j, w+time[j]});
        }
        return ans;
    }
};

int main()
{
    // skip
}