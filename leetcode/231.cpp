/*
 * Leetcode Easy 231. Power of Two
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
    bool isPowerOfTwo(int n)
    {
        int cnt = 0;
        for(int i = 0; i < 32; i++)
            cnt += (n >> i) & 1;
        return n >= 0 && cnt == 1;
    }
};

class Solution2 {
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && __popcount(n) == 1;
    }
};

class Solution3 {
public:
    bool isPowerOfTwo(int n)
    {
        if(n <= 0)
            return 0;
        double log2n = log2(n);
        return (log2n - floor(log2n)) < DBL_EPSILON;
    }
};

class Solution4 {
public:
    bool isPowerOfTwo(int n)
    {
        if(n <= 0)
            return 0;
        return (n & (n-1)) == 0;
    }
};

int main()
{
    // skip
}
