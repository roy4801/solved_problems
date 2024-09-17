/*
 * Leetcode Easy 884. Uncommon Words from Two Sentences
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
    vector<string> uncommonFromSentences(string a, string b)
    {
        vector<string> ans;
        string tmp;
        unordered_map<string, int> am, bm;
        stringstream ss(a);
        while(ss >> tmp)
            am[tmp]++;
        ss = stringstream{b};
        while(ss >> tmp)
            bm[tmp]++;

        for(auto& [s, cnt] : am)
            if(cnt == 1 && !bm.count(s))
                ans.push_back(s);
        for(auto& [s, cnt] : bm)
            if(cnt == 1 && !am.count(s))
                ans.push_back(s);

        return ans;
    }
};

int main()
{
    // skip
}