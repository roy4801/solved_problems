/*
 * Leetcode Medium 3039. Apply Operations to Make String Empty
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
    string lastNonEmptyString(string s)
    {
        int n = s.size();
        unordered_map<char,int> m;
        vector<int> v(n);
        
        int ma = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            m[s[i]]++;
            ma = max(ma, m[s[i]]);
            v[i] = m[s[i]];
        }
        
        string ans;
        for(int i = 0; i < n; i++)
            if(v[i] == ma)
                ans += s[i];
        
        return ans;
    }
};

int main()
{
    // skip
}