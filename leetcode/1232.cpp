/*
 * Leetcode Easy 1232. Check If It Is a Straight Line
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
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();

        auto slope = [&](int i, int j) {
            double x1 = c[i][0], y1 = c[i][1];
            double x2 = c[j][0], y2 = c[j][1];
            return (y2-y1)/(x2-x1);
        };

        sort(c.begin(), c.end(), [](auto &lhs, auto &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
        });

        double s = slope(0, 1);
        for(int i = 1; i < n-1; i++)
        {
            double tmp = slope(i, i+1);
            if(tmp != s)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    // skip
}
