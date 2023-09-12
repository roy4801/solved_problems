/*
 * Leetcode Easy 345. Reverse Vowels of a String
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
    inline bool ok(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s)
    {
        int i = 0, j = s.size()-1;
        
        while(i < j)
        {
            if(!ok(s[i])) i++;
            if(!ok(s[j])) j--;

            if(ok(s[i]) && ok(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};

/*
"hello"
"leetcode"
"aA"
"race a car"
*/

int main()
{
    // skip
}