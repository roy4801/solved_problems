/*
 * Leetcode Medium 991. Broken Calculator
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
    int brokenCalc(int s, int t)
    {
        int ans = 0;
        while(t > s)
        {
            if(t % 2 != 0)
            {
                t++;
                ans++;
            }
            else
            {
                t /= 2;
                ans++;
            }
        }

        ans += s - t;
        return ans;
    }
};

// 1 想到要反著做
// 2 觀察到 t < s 的可能

int main()
{
    // skip
}