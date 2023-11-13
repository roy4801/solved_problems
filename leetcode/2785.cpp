/*
 * Leetcode Medium 2785. Sort Vowels in a String
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

using P=pair<char,int>;
class Solution {
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s)
    {
        int n = s.size();
        vector<char> v;
        for(int i = 0; i < n; i++)
        {
            if(isVowel(s[i]))
                v.push_back(s[i]);
        }

        sort(v.begin(), v.end());

        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(isVowel(s[i]))
                s[i] = v[cnt++];
        }
        return s;
    }
};

int main()
{
    // skip
}
