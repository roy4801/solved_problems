/*
 * Leetcode Medium 791. Custom Sort String
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

// Custom Comparator O(nlogn)
class Solution {
public:
    string customSortString(string order, string s)
    {
        unordered_map<char,int> m;
        for(int i = 0; i < order.size(); i++)
            m[order[i]] = i;

        sort(s.begin(), s.end(), [&](char a, char b) {
            return m[a] < m[b];
        });
        return s;
    }
};

class Solution2 {
public:
    string customSortString(string order, string s)
    {
        unordered_map<char,int> m; // ch, count
        for(int i = 0; i < order.size(); i++)
            m[order[i]] = i;

        string ans;
        vector<string> v(order.size());
        for(int i = 0; i < s.size(); i++)
        {
            if(m.count(s[i]))
                v[m[s[i]]] += s[i];
            else
                ans += s[i];
        }
        
        for(int i = 0; i < order.size(); i++)
            ans += v[i];
        return ans;
    }
};

int main()
{
    // skip
}