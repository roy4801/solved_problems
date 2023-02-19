/*
 * Leetcode Medium 50. Pow(x, n)
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
    double solve(double x, int n)
    {
        if(n == 0)
            return 1.0;
        else if(n == 1)
            return x;
        double h = solve(x, n/2);
        if(n % 2 != 0)
            return h * h * x;
        else
            return h * h;
    }

    double myPow(double x, int n) {
        double ans = solve(x, abs(n));
        if(ans < 1e-5)
            return ans;
        if(n < 0)
            ans = 1.0 / ans;
        return ans ;
    }
};

int main()
{
    vector<pair<double, int>> in = {
        {2.00000, 10},
        {2.10000, 3},
        {2.00000, -1},
        {2.00000, -2147483648},
    };
    for(auto &&[x, n] : in)
    {
        DBG(Solution{}.myPow(x, n));
    }
}