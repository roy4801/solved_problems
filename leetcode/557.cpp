/*
 * Leetcode Easy 557. Reverse Words in a String III
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
    string ans;
    void rev(int a, int b)
    {
        while(a <= b)
            swap(ans[a++], ans[b--]);
    }
    
    string reverseWords(string S)
    {
        ans = S;
        
        int s = 0;
        for(int e = 0; e < S.size(); e++)
        {
            if(ans[e] == ' ')
            {
                //printf("%d %d\n", s, e);
                rev(s, e-1);
                s = e+1;
            }
        }
        rev(s, S.size()-1);
        return ans;
    }
};

int main()
{
    // skip
}