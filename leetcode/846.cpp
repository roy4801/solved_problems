/*
 * Leetcode Medium 846. Hand of Straights
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

// O(n^2) slow!
class Solution {
public:
    const double eps = numeric_limits<double>::epsilon();
    bool isNStraightHand(vector<int>& hand, int siz)
    {
        map<int,int> m; // num -> cnt
        for(int i : hand)
            m[i]++;

        int n = m.size();
        vector<int> k; // keys
        k.reserve(n);
        for(auto [num, cnt] : m)
            k.push_back(num);

        for(int i = 0; i <= n-siz; i++)
        {
            // Is i+0 ~ i+j consecutive
            double sum = 0;
            for(int j = 0; j < siz; j++)
                sum += k[i+j];
            if(sum/siz - (siz-1)/2.0 - k[i] > eps)
                continue;
            // m[i...i+siz] -= min(m[i], m[i+1], m[i+2], ..., m[i+siz])
            int tmp = INT_MAX;
            for(int j = 0; j < siz; j++)
                tmp = min(tmp, m[k[i+j]]);
            for(int j = 0; j < siz; j++)
                m[k[i+j]] -= tmp;
            skip:
        }

        int z = 0;
        for(int i = 0; i < n; i++)
            if(m[k[i]] == 0)
                z++;
        return z == n;
    }
};
int main()
{
    // skip
}