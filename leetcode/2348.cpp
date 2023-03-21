/*
 * Leetcode Medium 2348. Count Number of Texts
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
    long long zeroFilledSubarray(vector<int>& v)
    {
        int n = v.size();
        LL tmp = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(v[i] == 0)
            {
                tmp++;
            }
            else
            {
                ans += (1+tmp)*tmp/2;
                tmp = 0;
            }
        }

        ans += (1+tmp)*tmp/2;
        return ans;
    }
};

int main()
{
    using InputType = vector<int>;
    vector<InputType> in = {
        {1,3,0,0,2,0,0,4},
        {0,0,0,2,0,0},
        {2,10,2019},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.zeroFilledSubarray(i));
    }
}