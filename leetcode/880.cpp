/*
 * Leetcode Medium 880. Decoded String at Index
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

using LL = long long;
class Solution {
public:
    string decodeAtIndex(string s, int k)
    {
        int n = s.size();
        LL m = 0;

        for(int i = 0; i < n; i++)
        {
            if(isalpha(s[i]))
                m++;
            else
                m *= (s[i]-'0');
        }

        for(int i = n-1; i >= 0; i--)
        {
            if(k % m == 0 && isalpha(s[i]))
            {
                return (string) "" + s[i];
            }
            k %= m;

            if(isalpha(s[i]))
                m--;
            else
                m /= (s[i]-'0');
        }

        return "";
    }
};

int main()
{
    // skip
}