/*
 * Leetcode Medium 763. Partition Labels
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

class Solution
{
public:
    int m[26];
    vector<int> partitionLabels(string s)
    {
        vector<int> ans;
        // Build last appearance index map
        for(int i = 0; i < s.size(); i++)
            m[s[i]-'a'] = i;
        
        int l = 0, r = m[s[0]-'a']; // [l, r] is a gorup
        for(int i = 0; i < s.size(); i++)
        {
            // Update the right bound if possible
            if(m[s[i]-'a'] > r)
                r = m[s[i]-'a'];
            // end
            if(i == r)
            {
                //printf("%d %d\n", l, r);
                ans.push_back(r-l+1);
                l = i+1;
                r = l < s.size() ? m[s[l]-'a'] : l;
            }
        }
        
        if(l < s.size())
            ans.push_back(r-l+1);
        
        return ans;
    }
};

int main()
{
    // pass
}
