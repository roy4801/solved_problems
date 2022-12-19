/*
 * Leetcode Easy 1971. Find if Path Exists in Graph
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

#define N 200000
struct Disjoint
{
    int p[N+5];
    void init(int n)
    {
        for(int i = 0; i <= n; i++)
            p[i] = i;
    }
    int find(int x)
    {
        return (p[x]==x) ? x : (p[x] = find(p[x]));
    }
    void uni(int a, int b)
    {
        p[find(a)] = find(b);
    }
};

class Solution {
public:
    Disjoint set;
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst)
    {
        set.init(n);
        for(auto i : edges)
        {
            auto &&[a, b] = tie(i[0], i[1]);
            set.uni(a, b);
        }
        // printf("> %d %d\n", set.find(src), set.find(dst));
        return set.find(src) == set.find(dst);
    }
};

int main()
{
    // skip
}