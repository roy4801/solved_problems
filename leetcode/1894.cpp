/*
 * Leetcode Medium 1894. Find the Student that Will Replace the Chalk
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
    int chalkReplacer(vector<int>& ch, int _k)
    {
        int n = ch.size();

        LL k = _k;
        LL sum = accumulate(ch.begin(), ch.end(), 0LL);
        if(k >= sum)
        {
            k %= sum;
        }

        int i = 0;
        while(k)
        {
            if(k >= ch[i])
                k -= ch[i++];
            else
                return i;
            if(i >= n)
                i -= n;
        }
        return i;
    }
};

int main()
{
    // skip
}