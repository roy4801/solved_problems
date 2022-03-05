/*
 * Leetcode Medium 740. Delete and Earn
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back
#define N 20000

class Solution {
public:
    vector<int> v;
    int dp[N+5];

    int solve(int i)
    {
        if(i >= v.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int cur = v[i], sum = v[i];
        int j = i+1;

        // Sum up for cur val
        while(j < v.size() && v[j] == cur)
            sum += v[j++];

        int jmp = j;

        // Skip next val
        while(j < v.size() && v[j] == cur+1)
            j++;

        return dp[i] = max(sum + solve(j), solve(jmp));
    }

    int deleteAndEarn(vector<int>& nums)
    {
        v = nums;
        sort(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));
        return solve(0);
    }
};

int main()
{
    // vector<int> v = {2,2,3,3,3,4};
    // vector<int> v = {3,4,2};
    // vector<int> v = {3,3,3,4,2};
    vector<int> v = {12,32,93,17,100,72,40,71,37,92,58,34,29,78,11,84,77,90,92,35,12,5,27,92,91,23,65,91,85,14,42,28,80,85,38,71,62,82,66,3,33,33,55,60,48,78,63,11,20,51,78,42,37,21,100,13,60,57,91,53,49,15,45,19,51,2,96,22,32,2,46,62,58,11,29,6,74,38,70,97,4,22,76,19,1,90,63,55,64,44,90,51,36,16,65,95,64,59,53,93};
    cout << Solution{}.deleteAndEarn(v) << '\n';
}