/*
 * Leetcode Easy 1608. Special Array With X Elements Greater Than or Equal X
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
    int specialArray(vector<int>& nums)
    {
        int n = nums.size();
        if(nums.empty())
            return 0;

        for(int x = 1; x <= 1000; x++)
        {
            int cnt = 0;
            for(int j : nums)
                if(j >= x)
                    cnt++;
            if(cnt == x)
                return x;
        }
        return -1;
    }
};

int main()
{
    // skip
}