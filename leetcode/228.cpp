/*
 * Leetcode Easy 228. Summary Ranges
 * author: roy4801
 * AC(C++) 0ms 6.9MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& n)
    {
        if(n.empty()) return {};
        
        vector<string> ans;
        
        int l = n[0];
        for(int i = 1; i < n.size(); i++)
        {
            l = min(l, n[i-1]);

            if(n[i]-1 != n[i-1])
            {
                printf("%d->%d\n", l, n[i-1]);
                if(l == n[i-1])
                    ans.push_back(to_string(l));
                else
                    ans.push_back(to_string(l) + "->" + to_string(n[i-1]));
                l = n[i];
            }
        }
        
        if(l == n.back())
            ans.push_back(to_string(l));
        else
            ans.push_back(to_string(l) + "->" + to_string(n.back()));
        return ans;
    }
};

int main()
{
    vector<int> v = {0,1,2,4,5,7};
    Solution{}.summaryRanges(v);
}