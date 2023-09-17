/*
 * Leetcode Hard 847. Shortest Path Visiting All Nodes
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

#define V(x) (1<<(x))

class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int n;
    vector<vector<int>> dis; // shortest distance from i to j

    // Get length of the shortest path visited every node start from node i
    vector<vector<int>> memo; // n, 1<<n
    int solve(int i, int vis)
    {
        // is the state (i, vis) visited?
        if(memo[i][vis] != -1)
            return memo[i][vis];

        // visited all nodes?
        if(vis == V(n)-1)
            return 0;

        int ans = INT_MAX;
        for(int j = 0; j < n; j++)
        {
            // node j hasn't been visited
            if((vis & V(j)) == 0)
            {
                // shortest distance from i to j
                int d = dis[i][j]; 
                // after visit j, the short path length that go visit the remaining node start from node j
                d += solve(j, vis | V(j));
                ans = min(ans, d);
            }
        }

        return memo[i][vis] = ans; // memo
    }

    int shortestPathLength(vector<vector<int>>& graph)
    {
        n = graph.size();

        // 1. build graph (to distance matrix)
        dis.resize(n, vector<int>(n, inf));
        for(int i = 0; i < n; i++)
        {
            dis[i][i] = 0;
            for(int j : graph[i])
                dis[i][j] = 1;
        }

        // 2. floyd-warshall
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);

        // 3. dfs (try every node i=0..n-1)
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            memo.resize(n, vector<int>(1<<n, -1)); // clear to -1
            int si = solve(i, V(i)); // shortest path length starts from i
            ans = min(ans, si);
        }

        return ans;
    }
};

/* TLE
[[2,3,4,8],[8],[0],[0,8],[0,5,6],[4,7],[4],[5],[0,3,1]]
*/

int main()
{
    // skip
}