/*
 * Leetcode Easy 344. Reverse String
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
    void reverseString(vector<char>& s)
    {
        int i = 0, j = s.size()-1;
        while(i <= j)
        {
            swap(s[i++], s[j--]);
        }
    }
};

int main()
{
    // skip
}