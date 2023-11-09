/*
 * Leetcode Medium 1759. Count Number of Homogenous Substrings
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
    const int mod = 1e9+7;
    inline int calc(long long n)
    {
        return ((n+1)*n/2) % mod;
    }
    int countHomogenous(string s)
    {
        int n = s.size();
        int cnt = 1;
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i-1])
            {
                ans += calc(cnt);
                cnt = 1;
            }
            else
                cnt++;
        }
        ans += calc(cnt);
        return ans;
    }
};

int main()
{
    // skip
}
