/*
 * Leetcode Medium 1750. Minimum Length of String After Deleting Similar Ends
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
    int minimumLength(string s)
    {
        int n = s.size();

        int i = 0, j = n-1;
        while(i < j && s[i] == s[j])
        {
            char c = s[i];
            i++;
            j--;
            while(i < n && s[i] == c)
            {
                i++;
            }
            while(j >= 0 && s[j] == c)
            {
                j--;
            }
        }
        return i <＝ j ? j-i+1 : 0;
    }
};

int main()
{
    // skip
}
