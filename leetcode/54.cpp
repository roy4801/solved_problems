/*
 * Leetcode Medium 54. Spiral Matrix
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

using P=pair<int,int>;
#define X first
#define Y second
#define N 100

class Solution {
public:
    int n, m;
    bool vis[N+5];
    bool isEnd()
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i*m+j])
                    return false;
        return true;
    }
    vector<int> spiralOrder(vector<vector<int>>& M)
    {
        vector<int> ans;
        n = M.size(), m = M[0].size();
        int i = 0, j = 0;
        int dir = 0;
        P dirOff[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        auto check = [&](int i, int j)
        {
            return (0 <= i && i < n && 0 <= j && j < m) && !vis[i*m+j];
        };

        ans.push_back(M[0][0]);
        vis[0] = true;

        ans.reserve(n*m);
        while(!isEnd())
        {
            int ni = i + dirOff[dir].X,
                nj = j + dirOff[dir].Y;
            if(!check(ni, nj))
            {
                dir++;
                if(dir >= 4)
                    dir -= 4;
                continue;
            }
            else
            {
                i = ni;
                j = nj;
                ans.push_back(M[i][j]);
                vis[i*m+j] = true;
            }
        }
        return ans;
    }
};

int main()
{
    using InputType = vector<vector<int>>;
    vector<InputType> in = {
        {{1,2,3},{4,5,6},{7,8,9}},
        {{1,2,3,4},{5,6,7,8},{9,10,11,12}},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.spiralOrder(i));
    }
}