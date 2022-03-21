/*
 * Leetcode Medium 2212. Maximum Points in an Archery Competition
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

// enumeration 2^12
// bitset is too slow
class Solution
{
public:
    vector<int> maximumBobPoints(int n, vector<int>& a)
    {
        int limit = (1 << 12);// 111 1111 1111 
        int maxB = INT_MIN;
        vector<int> ans;
        
        for(int i = 1; i < limit; i++)
        {
            int arrow = 0, score = 0;
            vector<int> b(12, 0);

            for(int j = 0; j < 12; j++)
            {
                // i 的第 j 個 bit 是否 == 1
                if((i >> j) & 1)
                {
                    arrow += a[j]+1;
                    score += j;
                    b[j] = a[j]+1;
                }
            }

            if(arrow <= n && score > maxB)
            {
                maxB = score;
                if(arrow != n)
                    b[0] += n - arrow;
                ans = b;
            }
        }
        
        return ans;
    }
};

int main()
{
    int n = 9;
    vector<int> a = {1,1,0,1,0,0,2,1,0,1,2,0};
    // cout << a.size() << '\n';
    // int n = 89;
    // vector<int> a = {3,2,28,1,7,1,16,7,3,13,3,5};
    auto x = Solution{}.maximumBobPoints(n, a);
    DBG(x);
}