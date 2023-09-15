/*
 * Leetcode Medium 1584. Min Cost to Connect All Points
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
    int dis(vector<int>& a, vector<int>& b)
    {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    vector<array<int,3>> e; // weight, from, to

    vector<int> p;
    void init(int n) { p.resize(n+1); for(int i = 0; i <= n; i++) p[i] = i; }
    int find(int x) { return x == p[x] ? x : p[x]=find(p[x]); }
    void uni(int a, int b) { p[find(a)] = find(b); }
    bool isSame(int a, int b) { return find(a) == find(b); }

    int minCostConnectPoints(vector<vector<int>>& p)
    {
        int n = p.size();
        init(n);

        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
            {
                int d = dis(p[i], p[j]);
                e.push_back({d, i, j});
            }

        sort(e.begin(), e.end());
        int ans = 0;
        for(int i = 0; i < e.size(); i++)
        {
            int a = e[i][1], b = e[i][2];
            if(!isSame(a, b))
            {
                ans += e[i][0];
                uni(a, b);
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
