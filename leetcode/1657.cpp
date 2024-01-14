/*
 * Leetcode Medium 1657. Determine if Two Strings Are Close
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
    bool closeStrings(string word1, string word2)
    {
        int a[26]={}, b[26]={};
        for(char c : word1) a[c-'a']++;
        for(char c : word2) b[c-'a']++;

        vector<bool> ea(26, 0), eb(26, 0); // if char exists = ea[ch]
        vector<int> va, vb; // count of same char
        for(int i = 0; i < 26; i++)
        {
            if(a[i])
            {
                ea[i] = 1;
                va.push_back(a[i]);
            }
            if(b[i])
            {
                eb[i] = 1;
                vb.push_back(b[i]);
            }
        }

        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        return va == vb && ea == eb;
    }
};

int main()
{
    // skip
}