/*
 * Leetcode Medium 2849. Determine if a Cell Is Reachable at a Given Time
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
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int d = max(abs(fx-sx), abs(fy-sy));
        if(sx == fx && sy == fy)
            return t != 1;
        else
            return d <= t;
    }
};

int main()
{
    // skip
}