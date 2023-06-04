/*
 * Leetcode Medium 547. Number of Provinces
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

class Solution
{
public:
    // disjoint set
    vector<int> p;
    void init(int n)
    {
        p.resize(n);
        for(int i = 0; i < n; i++)
            p[i] = i;
    }
    int find(int x)
    {
        return p[x] == x ? x : (p[x]=find(p[x]));
    }
    void uni(int a, int b)
    {
        p[find(a)] = find(b);
    }

    int findCircleNum(vector<vector<int>>& G)
    {
        int n = G.size();
        init(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(G[i][j] && find(i) != find(j))
                {
                    uni(i, j);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            if(p[i] == i)
                ans++;

        return ans;
    }
};

int main()
{
    // skip
}