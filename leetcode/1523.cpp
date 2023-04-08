/*
 * Leetcode Easy 1523. Count Odd Numbers in an Interval Range
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

class Solution {
public:
    int countOdds(int a, int b)
    {
        if(a % 2 == 0)
            a++;
        if(b % 2 == 0)
            b--;
        return (b-a)/2+1;
    }
};

int main()
{
    // skip
}