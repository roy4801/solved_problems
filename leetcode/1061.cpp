/*
 * Leetcode Medium 1061. Lexicographically Smallest Equivalent String
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

#define N 200
struct disjoint
{
    int p[N+5];
    disjoint()
    {
        for(int i = 0; i <= N; i++)
            p[i] = i;
    }
    int find(int x)
    {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
    void uni(int a, int b)
    {
        p[find(a)] = find(b);
    }
    bool isSame(int a, int b)
    {
        return find(a) == find(b);
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(), m = baseStr.size();
        string ans;
        disjoint s;

        for(int i = 0; i < n; i++)
        {
            s.uni(s1[i], s2[i]);
        }

        for(int i = 0; i < m; i++)
        {
            char c = baseStr[i];

            for(char j = 'a'; j <= 'z'; j++)
            {
                if(s.isSame(c, j))
                {
                    ans += j;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    using AnsInput = tuple<string, string, string>;
    vector<AnsInput> in = {
        {"abc", "cde", "eed"},
        {"parker", "morris", "parser"},
        {"hello", "world", "hold"},
        {"leetcode", "programs", "sourcecode"},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.smallestEquivalentString(get<0>(i), get<1>(i), get<2>(i)));
    }
}