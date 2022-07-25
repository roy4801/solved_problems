/*
 * Leetcode Easy 242. Valid Anagram
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
    int sf[26], tf[26];;
    bool isAnagram(string s, string t)
    {
        for(char c : s)
            sf[c-'a']++;
        
        for(char c : t)
            tf[c-'a']++;
        
        return equal(sf, sf+26, tf);
    }
};

int main()
{
    // skip
}