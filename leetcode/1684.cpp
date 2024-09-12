/*
 * Leetcode Easy 1684. Count the Number of Consistent Strings
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
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        bool vis[26] = {};
        for(char c : allowed)
            vis[c-'a'] = 1;
        int ans = 0;
        for(auto& w : words)
        {
            for(char c : w)
                if(!vis[c-'a'])
                    goto end;
            ans++;
            end:
        }
        return ans;
    }
};

int main()
{
    // skip
}