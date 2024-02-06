/*
 * Leetcode Medium 49. Group Anagrams
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
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, int> m;
        int gid = 0;

        for(auto& s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if(!m.count(tmp))
                m[tmp] = gid++;
        }

        ans.resize(m.size());
        for(auto& s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            ans[m[tmp]].push_back(s);
        }

        return ans;
    }
};

int main()
{
    // skip
}
