/*
 * Leetcode Easy 859. Buddy Strings
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
    bool buddyStrings(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;
        int a[26]={0}, b[26]={0};
        for(int i = 0; i < n; i++) a[s[i]-'a']++;
        for(int i = 0; i < m; i++) b[t[i]-'a']++;
        bool eq = equal(a, a+26, b);
        if(s == t)
        {
            bool ok = false;
            for(int i = 0; i < 26; i++)
            {
                if(a[i] >= 2)
                    ok |= 1;
            }
            return ok && eq;
        }
        else
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(s[i] != t[i])
                    cnt++;
            }
            return cnt == 2 && eq;
        }
    }
};


int main()
{
    // skip
}