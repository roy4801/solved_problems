/*
 * Leetcode Medium 678. Valid Parenthesis String
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
    bool checkValidString(string s)
    {
        int n = s.size();
        vector<int> left;
        vector<int> a;

        for(int i = 0; i < n; i++)
        {
            char c = s[i];
            if(c == '(')
            {
                left.push_back(i);
            }
            else if(c == '*')
            {
                a.push_back(i);
            }
            else // )
            {
                if(!left.empty())
                {
                    left.pop_back();
                }
                else if(!a.empty())
                {
                    a.pop_back();
                }
                else
                {
                    return 0;
                }
            }
        }

        while(!a.empty() && !left.empty())
        {
            if(a.back() < left.back())
                return 0;

            left.pop_back();
            a.pop_back();
        }
        return 1 && left.empty();
    }
};

int main()
{
    // skip
}