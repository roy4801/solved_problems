/*
 * Leetcode Medium 2779. Maximum Beauty of an Array After Applying Operation
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
    int maximumBeauty(vector<int>& v, int k)
    {
        vector<int> a, b;
        int n = v.size();
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++)
        {
            a.push_back(v[i]-k);
            b.push_back(v[i]+k);
        }
        
        int ans = INT_MIN;
        int cur = 0;
        int i = 0, j = 0;
        while(i < n)
        {
            if(a[i] <= b[j])
            {
                cur++;
                i++;
            }
            else if(a[i] > b[j])
            {
                cur--;
                j++;
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};

int main()
{
    // skip
}