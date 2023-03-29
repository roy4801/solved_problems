/*
 * Leetcode Hard 1402. Reducing Dishes
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
    int maxSatisfaction(vector<int>& v)
    {
        sort(v.begin(), v.end());
        int n = v.size();
        int ans = INT_MIN;
        for(int i = n-1; i >= 0; i--)
        {
            int tmp = 0;
            for(int j = 0; j < n-i; j++)
            {
                tmp += v[i+j] * (j+1);
            }
            ans = max(ans, tmp);
        }
        return ans >= 0 ? ans : 0;
    }
};

int main()
{
    // skip
}