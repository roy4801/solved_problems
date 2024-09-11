/*
 * Leetcode Easy 2220. Minimum Bit Flips to Convert Number
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
    int minBitFlips(int start, int goal)
    { 
        if(!start && !goal)
            return 0;
        int ans = 0;
        int siz = ceil(log2(max(start, goal)))+1;
        start ^= goal;
        for(int i = 0; i < siz; i++)
            ans += (bool)(start & (1<<i));
        return ans;
    }
};

int main()
{
    // skip
}