/*
 * Leetcode Medium 802. Find Eventual Safe States
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
    vector<int> eventualSafeNodes(vector<vector<int>>& G)
    {
        int n = G.size();
        vector<vector<int>> R(n, vector<int>{});
        vector<int> od(n, 0);
        // 統計出度、建反向圖
        for(int i = 0; i < n; i++)
        {
            for(int j : G[i])
            {
                R[j].push_back(i);
                od[i]++;
            }
        }
        // 找出度是 0 的點
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!od[i])
                q.push(i);
        // 對於點 i (出度=0) 將連到點i的點j之出度-1 (相當於把點i拔掉)
        vector<int> ans;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            ans.push_back(i);

            for(int j : R[i])
            {
                od[j]--;
                if(od[j] <= 0)
                    q.push(j);
            }
        }
        // ans 未排序
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    // skip
}