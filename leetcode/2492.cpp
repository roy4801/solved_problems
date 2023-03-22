/*
 * Leetcode Medium 2492. Minimum Score of a Path Between Two Cities
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

#define N 100000
vector<P> G[N+5]; // [fr] -> (to, wei)
bool vis[N+5];
int en; // end num
int ans;

// TLE
class Solution {
public:
    void dfs(int s)
    {
        if(s == en)
        {
            return;
        }

        for(auto &&[to, wei] : G[s])
        {
            if(!vis[to])
            {
                vis[to] = true;
                ans = min(ans, wei);
                dfs(to);
                vis[to] = false;
            }
        }
    }

    int minScore(int n, vector<vector<int>>& e)
    {
        fill(vis, vis+n+1, false);
        for(int i = 1; i <= n; i++) G[i].clear();
        en = n;
        ans = INT_MAX;

        for(auto &i : e)
        {
            G[i[0]].emplace_back(i[1], i[2]);
            G[i[1]].emplace_back(i[0], i[2]);
        }

        vis[1] = true;
        dfs(1);

        return ans;
    }
};

// AC
class Solution2 {
public:
    void dfs(int s)
    {
        for(auto &&[to, wei] : G[s])
        {
            ans = min(ans, wei);
            if(!vis[to])
            {
                vis[s] = true;
                dfs(to);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& e)
    {
        fill(vis, vis+n+1, false);
        for(int i = 0; i <= n; i++) G[i].clear();
        en = n;
        ans = INT_MAX;

        for(auto &i : e)
        {
            G[i[0]].emplace_back(i[1], i[2]);
            G[i[1]].emplace_back(i[0], i[2]);
        }

        vis[1] = true;
        dfs(1);

        return ans;
    }
};

int main()
{
    using InputType = pair<int, vector<vector<int>>>;
    vector<InputType> in = {
        {4, {{1,2,9},{2,3,6},{2,4,5},{1,4,7}}},
        {6, {{4,5,7468},{6,2,7173},{6,3,8365},{2,3,7674},{5,6,7852},{1,2,8547},{2,4,1885},{2,5,5192},{1,3,4065},{1,4,7357}}},
    };
    for(auto &i : in)
    {
        DBG(Solution2{}.minScore(i.X, i.Y));
    }
}