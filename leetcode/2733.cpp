/*
 * Leetcode Easy 2733. Neither Minimum nor Maximum
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
    int findNonMinOrMax(vector<int>& v) {
        int n = v.size();
        if(n <= 2) return -1;
        
        sort(v.begin(), v.end());
        return v[1];
    }
};

int main()
{
    // skip
}