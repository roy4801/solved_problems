/*
 * Leetcode Easy 121. Best Time to Buy and Sell Stock
 * author: roy4801
 * (C++)
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

// TLE
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                ans = max(ans, prices[j] - prices[i]);
        return ans < 0 ? 0 : ans;
    }
};

// AC 13ms 105.2MB
class Solution {
public:
    int maxProfit(vector<int>& p)
    {
        int n = p.size();
        int a = INT_MAX, b = INT_MIN;
        vector<int> A(n), B(n);
        int ans = INT_MIN;

        for(int i = 0, j = n-1; i < n; i++)
        {
            if(a > p[i])
                a = p[i];
            A[i] = a;
        }

        for(int i = n-1; i >= 0; i--)
        {
            if(b < p[i])
                b = p[i];
            B[i] = b;
        }

        for(int i = 0; i < n; i++)
        {
            ans = max(ans, abs(A[i] - B[i]));
        }
        return ans;
    }
};

// AC 0ms 97.5MB
class Solution {
public:
    int maxProfit(vector<int>& p)
    {
        int n = p.size();
        int m = p[0];
        int ans = INT_MIN;

        for(int i = 1; i < n; i++)
        {
            if(m < p[i])
            {
                ans = max(ans, p[i] - m);
            }
            else
            {
                m = p[i];
            }
        }
        return ans < 0 ? 0 : ans;
    }
};

int main()
{
    // skip
}
