/*
 * Leetcode Easy 191. Number of 1 Bits
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
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n)
        {
            ans++;
            n &= n-1;
        }
        return ans;
    }
};

class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        return __popcount(n);
    }
};

int main()
{
    // skip
}
