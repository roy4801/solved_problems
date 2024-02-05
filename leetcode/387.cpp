/*
 * Leetcode Easy 387. First Unique Character in a String
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
    int firstUniqChar(string s)
    {
        int ans = 0;
        int cnt[26] = {0};
        for(char c : s)
            cnt[c-'a']++;
        for(int i = 0; i < s.size(); i++)
            if(cnt[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};

int main()
{
    // skip
}
