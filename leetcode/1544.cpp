/*
 * Leetcode Easy 1544. Make The String Great
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
    string makeGood(string s)
    {
        while(1)
        {
        start:
            int n = s.size();
            for(int i = 0; i < n-1; i++)
            {
                // eE | Ee
                if(s[i] == tolower(s[i+1]) && s[i+1] == toupper(s[i]) ||
                   s[i+1] == tolower(s[i]) && s[i] == toupper(s[i+1]))
                {
                    s = s.erase(i, 2);
                    goto start;
                }
            }
            break;
        }
        return s;
    }
};

int main()
{
    // skip
}