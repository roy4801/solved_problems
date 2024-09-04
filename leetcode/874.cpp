/*
 * Leetcode Medium 874. Walking Robot Simulation
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
    int robotSim(vector<int>& cmds, vector<vector<int>>& ob)
    {
        int n = cmds.size();
        int x = 0, y = 0, d = 0;
        int dir[][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        set<vector<int>> s(ob.begin(), ob.end());
        int ans = INT_MIN;
        
        for(int c : cmds)
        {
            switch(c)
            {
                case -2: // l
                    d -= 1;
                    if(d < 0)
                        d += 4;
                    break;
                case -1: // r
                    d += 1;
                    if(d >= 4)
                        d -= 4;
                    break;

                default:
                {
                    for(int i = 0; i < c; i++)
                    {
                        int nx = x + dir[d][0], ny = y + dir[d][1];
                        if(!s.count({nx, ny}))
                        {
                            x = nx;
                            y = ny;
                        }
                        ans = max(ans, x*x + y*y);
                    }
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}