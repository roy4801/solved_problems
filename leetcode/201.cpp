/*
 * Leetcode Medium 201. Bitwise AND of Numbers Range
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
    int rangeBitwiseAnd(int left, int right) {
        if(!left || !right) return 0;
        if(left == right) return left;
        int a = log2(left), b = log2(right);
        int ans = 0;
        if(a == b)
        {
            ans = left;
            for(long long i = left; i <= right; i++)
                ans &= i;
        }
        return a == b ? ans : 0;
    }
};

int main()
{
    // skip
}
