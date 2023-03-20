/*
 * Leetcode Easy 605. Can Place Flowers
 * author: roy4801
 * (C++)
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

class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n)
    {
        int ans = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] == 0)
            {
                bool ok = true;
                if(i-1 >= 0 && v[i-1] == 1)
                {
                    ok = false;
                }
                if(i+1 <= v.size()-1 && v[i+1] == 1)
                {
                    ok = false;
                }
                if(ok)
                {
                    // printf("> %d\n", i);
                    ans++;
                    v[i] = 1;
                }
            }
        }
        // DBG(ans);
        return ans >= n;
    }
};

int main()
{
    using InputType=pair<vector<int>, int>;
    vector<InputType> in = {
        {{1,0,0,0,1}, 1},
        {{1,0,0,0,1}, 2},
        {{1,0,0,0,0,1}, 2},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.canPlaceFlowers(i.X, i.Y));
    }
}