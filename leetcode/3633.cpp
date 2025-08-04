/*
 * Leetcode Easy 3633. Earliest Finish Time for Land and Water Rides I
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
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int tmp = landStartTime[i] + landDuration[i];
                if(tmp >= waterStartTime[j])
                {
                    tmp += waterDuration[j];
                }
                else
                {
                    tmp += waterStartTime[j] - tmp + waterDuration[j];
                }
                ans = min(ans, tmp);
            }
        }
        for(int j = 0; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                int tmp = waterStartTime[j] + waterDuration[j];
                if(tmp >= landStartTime[i])
                {
                    tmp += landDuration[i];
                }
                else
                {
                    tmp += landStartTime[i] - tmp + landDuration[i];
                }
                ans = min(ans, tmp);
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}
