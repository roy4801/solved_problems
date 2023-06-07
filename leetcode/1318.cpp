/*
 * Leetcode Medium 1318. Minimum Flips to Make a OR b Equal to c
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
    int minFlips(int a, int b, int c)
    {
        if(a == b && b == c)
            return 0;

        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            int mask = (1 << i);
            bool u = a & mask, d = b & mask, an = c & mask;

            if(an)
            {
                if(u && d)
                {
                    //
                }
                else if((!u && d) || (u && !d))
                {
                    //
                }
                else if(!u && !d)
                {
                    ans++;
                }
            }
            else
            {
                if(u && d)
                {
                    ans += 2;
                }
                else if((!u && d) || (u && !d))
                {
                    ans += 1;
                }
                else if(!u && !d)
                {
                    //
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
