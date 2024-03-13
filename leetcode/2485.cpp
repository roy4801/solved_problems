/*
 * Leetcode Easy 2485. Find the Pivot Integer
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
    int pivotInteger(int n)
    {
        vector<int> sum(n+1);
        for(int i = 1; i <= n; i++)
        {
            sum[i] = sum[i-1] + i;
        }

        for(int i = 1; i <= n; i++)
        {
            int a = sum[i]-sum[1]+1; // sum(1, i)
            int b = sum[n]-sum[i-1]; // sum(i, n)
            if(a == b)
                return i;
        }
        return -1;
    }
};

int main()
{
    // skip
}
