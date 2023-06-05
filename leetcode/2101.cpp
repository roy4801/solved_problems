/*
 * Leetcode Medium 2101. Detonate the Maximum Bombs
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

using LL=long long;
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& b)
    {
        int n = b.size();

        // i 爆炸 j 會不會炸到
        auto check = [&](int i, int j) {
            double x1 = b[i][0], y1 = b[i][1], r1 = b[i][2];
            double x2 = b[j][0], y2 = b[j][1], r2 = b[j][2];
            return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) <= r1*r1;
        };
        
        auto bfs = [&](int i) {
            vector<bool> vis(n, false); // i 訪問過
            vector<int> bomb(n, 0); // bomb[i] = i 炸幾顆
            queue<int> q;
            q.push(i);
            bomb[i] = 1;
            vis[i] = true;

            while(!q.empty())
            {
                auto i = q.front(); q.pop();

                for(int j = 0; j < n; j++)
                {
                    if(i != j && check(i, j) && !vis[j])
                    {
                        q.push(j);
                        bomb[i]++;
                        vis[j] = true;
                    }
                }
            }

            return accumulate(bomb.begin(), bomb.end(), 0);
        };

        // 枚舉 i 當起點 bfs 找最大
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
            ans = max(ans, bfs(i));

        return ans;
    }
};

int main()
{
    // skip
}