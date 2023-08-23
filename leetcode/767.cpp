/*
 * Leetcode Easy 767. Prime Number of Set Bits in Binary Representation
 * author: roy4801
 * (C++)
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
    string reorganizeString(string s)
    {
        int ch[26] = {0};
        for(char c : s)
            ch[c-'a']++;

        int half = siz % 2 != 0 ? (siz+1)/2 : siz/2;
        for(int i = 0; i < 26; i++)
            if(ch[i] > half)
                return "";

        int siz = accumulate(ch, ch+26, 0);
        vector<array<int,2>> v; // <count, char>
        for(int i = 0; i < 26; i++)
            if(ch[i])
                v.push_back({ch[i], i});
        sort(v.begin(), v.end(), [](auto &lhs, auto &rhs) { return lhs[0] > rhs[0]; });

        int prev = -1;
        string ans;
        while(ans.size() < siz)
        {
            int i = 0;
            while(v[i][1] == prev)
                i++;
            ans += 'a'+v[i][1];
            v[i][0]--;
            prev = v[i][1];
            sort(v.begin(), v.end(), [](auto &lhs, auto &rhs) { return lhs[0] > rhs[0]; });
        }

        return ans;
    }
};

int main()
{
    // skip
}
