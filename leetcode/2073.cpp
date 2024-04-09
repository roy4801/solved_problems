/*
 * Leetcode Easy 2073. Time Needed to Buy Tickets
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
    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        int n = tickets.size();
        int ans = 0;
        while(tickets[k] > 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(tickets[i])
                {
                    tickets[i]--;
                    ans++;
                }

                if(tickets[k] <= 0)
                    break;
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}