/*
 * Leetcode Medium 1347. Minimum Number of Steps to Make Two Strings Anagram
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
    int minSteps(string s, string t)
    {
        int a[26] = {}, b[26] = {};
        for(char c : s) a[c-'a']++;
        for(char c : t) b[c-'a']++;

        int ans = 0;
        for(int i = 0; i < 26; i++)
            ans += abs(a[i] - b[i]);

        return ans / 2;
    }
};

int main()
{
    // skip
}