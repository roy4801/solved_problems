/*
 * Leetcode Medium 1493. Longest Subarray of 1's After Deleting One Element
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
    int longestSubarray(vector<int>& v)
    {
        int n = v.size();
        deque<int> z;
        int i = 0;
        int ans = INT_MIN;
        for(int j = 0; j < n; j++)
        {
            if(v[j] == 0)
            {
                if(!z.empty())
                {
                    i = z.front()+1;
                    z.pop_front();
                }
                z.push_back(j);
            }

            ans = max(ans, j-i+1);
        }
        ans -= 1;
        return ans;
    }
};

int main()
{
    // skip
}
