/*
 * Leetcode Easy 2540. Minimum Common Value
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
    int getCommon(vector<int>& a, vector<int>& b)
    {
        vector<int> v;
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v));
        return v.empty() ? -1 : v.front();
    }
};

int main()
{
    // skip
}
