/*
 * Leetcode Medium 49. Group Anagrams
 * author: roy4801
 * (C++)
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

class Solution {
public:
    unordered_map<string, int> m;
    int i = 0;
    int calc(const string& s)
    {
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        if(!m.count(tmp))
        {
            m[tmp] = i++;
        }
        return m[tmp];
    }
    vector<vector<string>> groupAnagrams(vector<string>& v)
    {
        vector<vector<string>> ans;
        
        for(auto &s : v)
            calc(s);

        ans.resize(i);
        for(auto &s : v)
        {
            ans[calc(s)].push_back(s);
        }
        return ans;
    }
};

int main()
{
    using InputType=vector<vector<string>>;
    InputType in = {
        {"eat","tea","tan","ate","nat","bat"},
        {""},
        {"a"},
        {"",""}
    };

    for(auto &i : in)
    {
        auto ans = Solution2{}.groupAnagrams(i);
        for(auto &i : ans)
        {
            for(auto &j : i)
                cout << "\"" << j << "\", ";
        }
        puts("");
    }
}