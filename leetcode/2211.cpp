/*
 * Leetcode Medium 2211. Count Collisions on a Road
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

class Solution
{
public:
    int countCollisions(string d)
    {
        int ans = 0, r = 0;
        
        for(int i = 1; i <= d.size()-1; i++)
        {
            // RS or SL
            if(d[i-1] == 'R' && d[i] == 'S' ||
               d[i-1] == 'S' && d[i] == 'L')
            {
                ans++;
                ans += r;
                r = 0;
                d[i-1] = d[i] = 'S';
            }
            // RL
            else if(d[i-1] == 'R' && d[i] == 'L')
            {
                ans += 2;
                ans += r;
                r = 0;
                d[i-1] = d[i] = 'S';
            }
            //  count R
            // e.g. RRL
            //      ^
            else if(d[i-1] == 'R')
                r++;
        }
        
        return ans;
    }
};

int main()
{
    // skip
}