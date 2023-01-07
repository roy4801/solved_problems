/*
 * Leetcode Medium 134. Gas Station
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curGas = 0;
        int si = 0; // start index
        for(int i = 0; i < 2*n; i++)
        {
            int idx = i;
            if(idx >= n)
                idx -= n;

            curGas += gas[idx] - cost[idx];

            if(curGas < 0)
            {
                si = i+1;
                curGas = 0;
            }
            else
            {
                if(i - si == n)
                {
                    return si;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<pair<vector<int>, vector<int>>> in = {
        {{1,2,3,4,5}, {3,4,5,1,2}},
        {{2,3,4}, {3,4,3}},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.canCompleteCircuit(i.X, i.Y));
    }
}

/*
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
*/