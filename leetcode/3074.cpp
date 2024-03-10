/*
 * Leetcode Easy 3074. Apple Redistribution into Boxes
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
    int minimumBoxes(vector<int>& a, vector<int>& c)
    {
        int sum = accumulate(a.begin(), a.end(), 0);
        sort(c.begin(), c.end(), greater<>());
        int ans = 0;
        for(int i : c)
        {
            if(sum > 0)
            {
                sum -= i;
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{
    // skip
}