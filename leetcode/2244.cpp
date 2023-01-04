/*
 * Leetcode Medium 2244. Minimum Rounds to Complete All Tasks
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
    int minimumRounds(vector<int>& N) {
        vector<int> v;
        int ans = 0, cnt = 1;
        sort(N.begin(), N.end());

        int i = 0;
        while(i < N.size())
        {
            if(i+1 < N.size() && N[i] == N[i+1])
            {
                cnt++;
            }
            else
            {
                v.push_back(cnt);
                cnt = 1;
            }
            i++;
        }

        for(int i : v)
        {
            if(i == 1)
                return -1;
            ans += i / 3;
            i %= 3;
            if(i)
                ans++;
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> in = {
        // {2,2,3,3,2,4,4,4,4,4},
        // {2,3,3},
        // {1,1000000000},
        {66,66,63,61,63,63,64,66,66,65,66,65,61,67,68,66,62,67,61,64,66,60,69,66,65,68,63,60,67,62,68,60,66,64,60,60,60,62,66,64,63,65,60,69,63,68,68,69,68,61}
    };

    for(auto &i : in)
        DBG(Solution{}.minimumRounds(i));
}