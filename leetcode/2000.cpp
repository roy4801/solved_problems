/*
 * Leetcode Easy 2000. Reverse Prefix of Word
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
    string reversePrefix(string word, char ch) {
        auto i = word.find(ch);
        if(i < word.size())
            reverse(word.begin(), word.begin()+i+1);
        return word;
    }
};

int main()
{
    // skip
}