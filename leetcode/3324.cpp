/*
 * Leetcode Medium 3324. Find the Sequence of Strings Appeared on the Screen
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
    vector<string> stringSequence(string target)
    {
        vector<string> ans;
        int n = target.size();
        string s(n, ' ');
        for(int i = 0; i < n; i++)
        {
            char c = target[i];
            while(s[i] != c)
            {
                if(s[i] == ' ')
                {
                    s[i] = 'a';
                }
                else
                {
                    s[i]++;
                }

                string tmp;
                for(char c : s)
                {
                    if(c == ' ') break;
                    tmp += c;
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

int main()
{
    DBG(Solution{}.stringSequence("abc"));
    DBG(Solution{}.stringSequence("he"));
}
