/*
 * Leetcode Easy 58. Length of Last Word
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
    int lengthOfLastWord(string s)
    {
        stringstream ss(s);
        string w;
        while(ss >> w);
        return w.size();
    }
};

int main()
{
    // skip
}
