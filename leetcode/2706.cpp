/*
 * Leetcode Medium 2706. Minimum Score by Changing Two Elements
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
    int buyChoco(vector<int>& prices, int money)
    {
        sort(prices.begin(), prices.end());
        return prices[0]+prices[1] <= money ?
               money-prices[0]-prices[1] :
               money;
    }
};

int main()
{
    // skip
}
