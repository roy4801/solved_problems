/*
 * Leetcode Medium 633. Sum of Square Numbers
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

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if(c == 0)
            return 1;
        
        // sqrt(c)^2 + 0^2 = c
        for(int a = 1; a <= sqrt(c); a++)
        {
            int a2 = a * a;
            int b = sqrt(c - a2); // b^2 = c - a^2
            if(a*a + b*b == c)
            {
                return 1;
            }
        }
        return 0;
    }
};

int main()
{
    // skip
}