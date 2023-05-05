/*
 * Leetcode Medium 1456. Maximum Number of Vowels in a Substring of Given Length 
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

class Solution {
public:
    bool isVowel(char c) { return c == 'a' || c == 'e' || c =='i' || c == 'o' || c =='u'; }
    int maxVowels(string s, int k)
    {
        int n = s.size();
        int i = 0, j = i+k-1;
        int ans = -1;

        int tmp = 0;
        for(int k = i; k <= j; k++)
        {
            if(isVowel(s[k]))
                tmp++;
        }
        ans = max(ans, tmp);
        while(j < n)
        {
            if(isVowel(s[i]))
                tmp--;
            i++, j++;
            if(isVowel(s[j]))
                tmp++;
            ans = max(ans, tmp);
        }
        return ans;
    }
};

int main()
{
    // skip
}
