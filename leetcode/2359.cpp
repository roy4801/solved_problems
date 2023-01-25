/*
 * Leetcode Medium 2359. Find Closest Node to Given Two Nodes
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
vector<int> G[N+5];
class Solution {
public:
    int n;
    vector<int> E;
    int A[N+5], B[N+5];

    void build()
    {
        n = E.size();
        for(int i = 0; i < E.size(); i++)
        {
            if(E[i] != -1)
                G[i].push_back(E[i]);
        }
    }

    bool visit[N+5];
    void dfs(int dis[N+5], int src)
    {
        memset(visit, 0, sizeof(visit));
        //
        queue<P> q;
        q.push(MP(src, 0));
        dis[src] = 0;
        visit[src] = true;

        while(!q.empty())
        {
            auto i = q.front(); q.pop();
            for(int j : G[i.X])
            {
                if(!visit[j])
                {
                    visit[j] = true;
                    dis[j] = i.Y+1;
                    q.push(MP(j, i.Y+1));
                }
            }
        }
        
    }

    int closestMeetingNode(vector<int>& _E, int a, int b) {
        E = _E;
        for(int i = 0; i <= N; i++) G[i].clear();
        memset(A, 0xff, sizeof(A));
        memset(B, 0xff, sizeof(B));
        //
        build();

        dfs(A, a);
        dfs(B, b);

        int ans = -1;
        int minv = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == -1 || B[i] == -1)
                continue;

            int m = max(A[i], B[i]);
            if(minv > m)
            {
                minv = m;
                ans = i;
            }
        }

        return ans;
    }
};

int main()
{
    using InputType=tuple<vector<int>, int, int>;
    vector<InputType> in = {
        {{2,2,3,-1}, 0, 1},
        {{1,2,-1}, 0, 2},
        {{4,4,8,-1,9,8,4,4,1,1}, 5, 6},
        {{4,4,4,5,1,2,2}, 1, 1},
        {{5,4,5,4,3,6,-1}, 0, 1},
    };
    for(auto &i : in)
    {
        auto &E = get<0>(i);
        auto a = get<1>(i);
        auto b = get<2>(i);
        DBG(Solution{}.closestMeetingNode(E, a, b));
    }
}