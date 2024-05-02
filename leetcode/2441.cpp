/*
 * Leetcode Easy 2441. Largest Positive Integer That Exists With Its Negative
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
    int findMaxK(vector<int>& nums)
    {
        unordered_set<int> s;
        for(int i : nums)
            s.insert(i);

        int m = -1;
        for(int i : nums)
        {
            if(i > 0 && s.count(-i) && i > m)
            {
                m = i;
            }
        }
        return m;
    }
};

int main()
{
    // skip
}
