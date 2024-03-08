/*
 * Leetcode Easy 3005. Count Elements With Maximum Frequency
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
    int maxFrequencyElements(vector<int>& nums) {
        int cnt[105] = {0};
        int n = nums.size();
        for(int i = 0; i < n; i++)
            cnt[nums[i]]++;

        int m = INT_MIN;
        for(int i = 1; i <= 100; i++)
            m = max(m, cnt[i]);
        int ans = 0;
        for(int i = 1; i <= 100; i++)
            ans += (cnt[i] == m ? cnt[i] : 0);
        return ans;
    }
};

int main()
{
    // skip
}
