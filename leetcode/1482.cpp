/*
 * Leetcode diff id. title
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
    int minDays(vector<int>& B, int m, int k)
    {
        int n = B.size();

        auto check = [&](int d) -> bool
        {
            int cnt = 0, g = 0;
            for(int i = 0; i < n; i++)
            {
                if(B[i] <= d)
                    cnt++;
                else
                    cnt = 0;
                if(cnt == k)
                {
                    g++;
                    cnt = 0;
                }
            }
            return g >= m;
        };
        

        // for(int i = 1; i <= 15; i++)
        //     printf("%d = %d\n", i, check(i));
        // return 0;
        // [l, r)
        int l = 1, r = 1e9+1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(check(mid)) // 
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        // printf("%d %d\n", l, r);
        return l == 1e9+1 ? -1 : l;
    }
};

int main()
{
    // skip
}
