/*
 * Leetcode Medium 2870. Minimum Number of Operations to Make Array Empty
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
    int minOperations(vector<int>& nums)
    {
        int ans = 0;
        int n = nums.size();
        map<int, int> m;

        for(int i : nums)
            m[i]++;

        for(auto [num, cnt] : m)
        {
            int tmp = 0;
            if(cnt <= 1)
                return -1;
            while(cnt)
            {
                int t3 = cnt - 3;
                if(t3 % 3 == 0 || t3 % 2 == 0)
                {
                    tmp++;
                    cnt -= 3;
                }
                else
                {
                    int t2 = cnt - 2;
                    if(t2 % 3 == 0 || t2 % 2 == 0)
                    {
                        tmp++;
                        cnt -= 2;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            ans += tmp;
        }

        return ans;
    }
};


int main()
{
    // skip
}
