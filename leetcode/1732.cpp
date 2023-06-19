/*
 * Leetcode Easy 1732. Find the Highest Altitude
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
    int largestAltitude(vector<int>& gain) {
        int tmp = 0;
        int ans = 0;

        for(int i : gain)
        {
            tmp += i;
            ans = max(ans, tmp);
        }
        return ans;
    }
};

int main()
{
    // skip
}