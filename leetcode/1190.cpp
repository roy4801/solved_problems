/*
 * Leetcode Medium 1190. Reverse Substrings Between Each Pair of Parentheses
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
    string reverseParentheses(string s)
    {
        int n = s.size();
        stack<int> stk;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                stk.push(i+1);
            }
            else if(s[i] == ')')
            {
                int l = stk.top(), r = i;
                stk.pop();
                reverse(s.begin()+l, s.begin()+r);
            }
        }

        auto fn = [](char c) { return c == '(' || c == ')'; };
        auto it = remove_if(s.begin(), s.end(), fn);
        s.erase(it, s.end());
        return s;
    }
};

int main()
{
    // skip
}