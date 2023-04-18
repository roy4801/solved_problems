/*
 * Leetcode Easy 1768. Merge Strings Alternately
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
    string mergeAlternately(string a, string b)
    {
        string s;
        int i = 0, j = 0;
        while(i < a.size() || j < b.size())
        {
            if(i < a.size())
                s += a[i++];
            if(j < b.size())
                s += b[j++];
        }
        return s;
    }
};

int main()
{
    // skip
}