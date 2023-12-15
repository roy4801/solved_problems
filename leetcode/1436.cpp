/*
 * Leetcode Easy 1436. Destination City
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
    unordered_set<string> s;
    string destCity(vector<vector<string>>& paths)
    {
        int e = paths.size();
        for(int i = 0; i < e; i++)
        {
            s.insert(paths[i][1]);
        }
        for(int i = 0; i < e; i++)
        {
            s.erase(paths[i][0]);
        }

        return *s.begin();
    }
};

class Solution2 {
public:
    unordered_map<string, int> m;
    unordered_map<int, string> rm;
    int id = 0;
    int GetID(string& s)
    {
        if(!m.count(s))
        {
            rm[id] = s;
            m[s] = id;
            id++;
        }
        return m[s];
    }

    vector<int> G[1005];
    string destCity(vector<vector<string>>& paths)
    {
        int e = paths.size();
        for(int i = 0; i < e; i++)
        {
            int a = GetID(paths[i][0]);
            int b = GetID(paths[i][1]);
            G[a].push_back(b);
        }

        for(int i = 0; i < m.size(); i++)
        {
            if(G[i].size() == 0)
            {
                return rm[i];
            }
        }
        return "";
    }
};

int main()
{
    // skip
}
