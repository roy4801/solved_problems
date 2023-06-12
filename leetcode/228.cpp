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
            if(n[i]-1 != n[i-1])
            {
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

class Solution2 {
public:
    vector<string> summaryRanges(vector<int>& v)
    {
        int n = v.size(), left = 0, right = 0;
        bool rw = false;
        vector<string> ans;
        int state = 0;
        // 0 = left
        // 1 = rigth

        if(n == 0)
            return ans;

        for(int i = 0; i < n;)
        {
        switch(state)
        {
            case 0:
            {
                left = v[i];
                state = 1;
                i++;
            }
            break;
            case 1:
            {
                if((LL)v[i] - v[i-1] == 1LL)
                {
                    right = v[i];
                    rw = true;
                    i++;
                }
                else
                {
                    if(rw && right - left > 0)
                        ans.push_back(to_string(left)+"->"+to_string(right));
                    else
                        ans.push_back(to_string(left));
                    state = 0;
                    left = right = 0;
                    rw = false;
                }
            }
            break;
        }
        }

        if(rw)
            ans.push_back(to_string(left)+"->"+to_string(right));
        else
            ans.push_back(to_string(left));

        return ans;
    }
};

int main()
{
    vector<int> v = {0,1,2,4,5,7};
    Solution{}.summaryRanges(v);
}