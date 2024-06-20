/*
 * Leetcode Medium 1552. Magnetic Force Between Two Balls
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
    int maxDistance(vector<int>& b, int m)
    {
        sort(b.begin(), b.end());
        int n = b.size();

        // check(d) = 如果以間隔 d 放球，能不能擺滿 m 顆
        auto check = [&](int d)
        {
            int prev = b[0], ball = 1;

            for(int i = 1; i < n && ball < m; i++)
            {
                int cur = b[i];
                if(cur - prev >= d)
                {
                    ball++;
                    prev = cur;
                }
            }
            return ball == m;
        };

        // 二分答案
        int l = 1, r = 1e9+1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(check(mid))
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        return (l <= 1e9) ? l-1 : 0;
    }
};

int main()
{

}