/*
 * Leetcode Easy 2917. Find the K-or of an Array
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
    int findKOr(vector<int>& nums, int k)
    {
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for(int j : nums)
            {
                if(j & (1<<i))
                    cnt++;
            }
            
            if(cnt >= k)
                ans += pow(2, i);
        }
        return ans;
    }
};

int main()
{
    // skip
}