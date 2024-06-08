/*
 * Leetcode Medium 648. Replace Words
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

struct trie
{
    bool end = 0;
    trie* next[26] = {0};
};
void trie_insert(trie* r, string& s)
{
    for(char c : s)
    {
        if(!r->next[c-'a'])
            r->next[c-'a'] = new trie();
        r = r->next[c-'a'];
    }
    r->end = 1;
}
string trie_query(trie* r, string& s)
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        char c = s[i];
        if(!r->next[c-'a'])
            return s;
        r = r->next[c-'a'];
        if(r->end)
            return s.substr(0, i+1);
    }
    return s;
}

class Solution
{
public:

    string replaceWords(vector<string>& dict, string s)
    {
        vector<string> sp;
        size_t pos = 0;
        while((pos = s.find(' ')) != string::npos)
        {
            sp.push_back(s.substr(0, pos));
            s.erase(0, pos+1);
        }
        if(!s.empty())
            sp.push_back(s);
        int n = sp.size();

        // build trie
        trie r;
        for(auto& i : dict)
            trie_insert(&r, i);

        for(auto& i : sp)
        {
            auto tmp = trie_query(&r, i);
            if(tmp != "")
                i = tmp;
        }

        string ans;
        for(int i = 0; i < n; i++)
            ans += (i ? " " : "") + sp[i];
        return ans;
    }
};


struct Trie
{
    struct trie_node
    {
        bool isEnd = 0;
        trie_node* next[26] = {0};
    };
    trie_node* r;

    Trie()
    {
        r = new trie_node;
    }

    void insert(string& s)
    {
        trie_node* tn = r;
        for(char c : s)
        {
            if(!tn->next[c-'a'])
                tn->next[c-'a'] = new trie_node();
            tn = tn->next[c-'a'];
        }
        tn->isEnd = 1;
    }

    string query(string& s)
    {
        trie_node* tn = r;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            char c = s[i];
            if(!tn->next[c-'a'])
                return s;
            tn = tn->next[c-'a'];
            if(tn->isEnd)
                return s.substr(0, i+1);
        }
        return s;
    }
};

int main()
{
    using InputType = tuple<vector<string>,string>;
    vector<InputType> v = {
        {{"a", "aa", "aaa", "aaaa"}, "a a a a a a a a b b a"}
    };

    for(auto& [dict, s] : v)
    {
        DBG(Solution{}.replaceWords(dict, s));
    }
}

/*
"a a a a a a a a b b a"
"a a a a a a a a b b a"
*/