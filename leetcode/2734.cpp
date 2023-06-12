/*
 * Leetcode Medium 2734. Lexicographically Smallest String After Substring Operation
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
    string smallestString(string s) {
        int n = s.size();
        
        int i = 0;
        while(i < n && s[i] == 'a') i++;

        int j = i;
        while(j < n && s[j] != 'a') j++;
        
        // [i, j) -> -1
        for(int a = i; a < j; a++)
        {
            s[a]--;
            if(s[a] < 'a')
                s[a] = 'z';
        }

        // case: all a
        if(i == j && i == n)
            s[n-1] = 'z';

        return s;
    }
};

int main()
{
    // skip
}