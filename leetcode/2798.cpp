/*
 * Leetcode Easy 2798. Number of Employees Who Met the Target
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
    int numberOfEmployeesWhoMetTarget(vector<int>& h, int t)
    {
        return count_if(h.begin(), h.end(), [&](int i) { return i >= t; });
    }
};

int main()
{
    // skip
}