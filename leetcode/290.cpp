/*
 * Leetcode Easy 290. Word Pattern
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

class Solution {
public:
    unordered_map<string, char> m;
    bool used[26];

    bool wordPattern(string patt, string s) {
        stringstream ss(s);
        string tok;
        vector<string> v;
        while(getline(ss, tok, ' '))
            v.push_back(tok);

        if(v.size() > patt.size())
            return false;
        
        for(int i = 0; i < patt.size(); i++)
        {
            if(i >= v.size())
                return false;

            if(!m.count(v[i]))
            {
                if(!used[patt[i]-'a'])
                {
                    m[v[i]] = patt[i];
                    used[patt[i]-'a'] = true;
                }
                else
                    return false;
            }
            else
            {
                if(m[v[i]] != patt[i])
                    return false;
            }
        }
        
        return true;
    }
};

int main()
{
    vector<pair<string,string>> in = {
        {"abba", "dog cat cat dog"},
        {"abba", "dog cat cat fish"},
        {"aaaa", "dog cat cat dog"},
        {"e", "eukera"},
        {"jquery", "jquery"},
        {"aaa", "aa aa aa aa"}
    };

    for(auto &&[a, b] : in)
    {
        DBG(Solution{}.wordPattern(a, b));
    }
}