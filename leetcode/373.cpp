/*
 * Leetcode Medium 373. Find K Pairs with Smallest Sums
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

using P=array<int,3>; // sum, i, j
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k)
    {
        vector<vector<int>> ans;
        auto cmp = [](auto &l, auto &r) {
            return l[0] > r[0];
        };
        priority_queue<P,vector<P>,decltype(cmp)> pq(cmp);
        map<vector<int>, bool> vis;
        int n = a.size(), m = b.size();

        pq.push({a[0]+b[0],0,0});
        while(!pq.empty())
        {
            auto [sum, i, j] = pq.top();
            pq.pop();

            if(k)
            {
                ans.push_back({a[i], b[j]});
                k--;
            }
            else
            {
                break;
            }

            if(i+1 < n && !vis[{i+1,j}])
            {
                vis[{i+1,j}] = 1;
                pq.push({a[i+1]+b[j], i+1, j});
            }
            if(j+1 < m && !vis[{i,j+1}])
            {
                vis[{i,j+1}] = 1;
                pq.push({a[i]+b[j+1], i, j+1});
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}