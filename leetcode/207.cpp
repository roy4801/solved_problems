/*
 * Leetcode Medium 207. Course Schedule
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
    bool canFinish(int n, vector<vector<int>>& preq)
    {
        int m = preq.size();
        vector<char> color(n); // 0, 1, 2
        vector<vector<int>> req(n, vector<int>{});

        function<bool(int)> dfs = [&](int x) -> bool
        {
            color[x] = 1;
            for(int y : req[x])
            {
                if(color[y] == 0)
                {
                    color[y] = 1;
                    if(dfs(y))
                        return 1;
                }
                else if(color[y] == 1)
                    return 1;
            }
            color[x] = 2;
            return 0;
        };

        for(int i = 0; i < m; i++)
        {
            int a = preq[i][0], b = preq[i][1];
            req[a].push_back(b);
        }

        for(int i = 0; i < n; i++)
            if(color[i] == 0 && dfs(i))
                return 0;
        return 1;
    }
};

int main()
{
    // skip
}
