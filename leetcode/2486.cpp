/*
 * Leetcode Medium 2486. Append Characters to String to Make Subsequence
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
    int appendCharacters(string s, string t)
    {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        while(i < n)
        {
            if(s[i] == t[j])
            {
                j++;
            }
            i++;
        }
        return m-j;
    }
};

int main()
{
    // skip
}