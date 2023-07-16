/*
 * Leetcode Easy 2778. Sum of Squares of Special Elements
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
    int sumOfSquares(vector<int>& v)
    {
        int n = v.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(n % (i+1) == 0)
                ans += v[i]*v[i];
        }
        return ans;
    }
};

int main()
{
    // skip
}