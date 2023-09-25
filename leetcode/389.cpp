/*
 * Leetcode Easy 389. Find the Difference
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
    char findTheDifference(string s, string t)
    {
        int n = s.size(), m = t.size();
        char cnt[26] = {0};

        for(int i = 0; i < n; i++)
            cnt[s[i]-'a']++;

        for(int i = 0; i < m; i++)
            if(!cnt[t[i]-'a'])
                return t[i];
            else
                cnt[t[i]-'a']--;

        return '\0';
    }
};

int main()
{
    // skip
}
