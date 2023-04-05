/*
 * Leetcode Medium 2439. Minimize Maximum of Array
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
    int minimizeArrayValue(vector<int>& v)
    {
        int n = v.size();

        LL total = v[0];
        int ans = v[0];
        for(int i = 1; i < n; i++)
        {
            total += v[i];

            auto tmp = (total+i)/(i+1);
            ans = max(ans, (int)tmp);
        }
        return ans;
    }
};

int main()
{
    // skip
}