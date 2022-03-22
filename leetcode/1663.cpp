/*
 * Leetcode Medium 1663. Smallest String With A Given Numeric Value
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

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string fr, mi, ba;
        
        while(k >= 1*(n-1)+26)
        {
            ba += 'z';
            k -= 26;
            n--;
        }
        
        while(n > 1)
        {
            fr += 'a';
            k--;
            n--;
        }
        
        if(k > 0)
            mi += 'a' + (k-1);
        
        // cout << fr << mi << ba << '\n';
        
        return fr + mi + ba;
    }
};

int main()
{
    // skip
}