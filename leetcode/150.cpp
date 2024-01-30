/*
 * Leetcode Medium 150. Evaluate Reverse Polish Notation
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

using LL=long long;
class Solution {
public:
    stack<LL> n;
    int evalRPN(vector<string>& s)
    {
        for(string i : s)
        {
            if(i != "+" && i != "-" && i != "*" && i != "/")
            {
                n.push(stoi(i));
            }
            else
            {
                LL a, b;
                b = n.top(), n.pop();
                a = n.top(), n.pop();
                // cout << a << ' ' << b << '\n';
                if(i == "+")
                    n.push(a+b);
                else if(i == "-")
                    n.push(a-b);
                else if(i == "*")
                    n.push(a*b);
                else if(i == "/")
                    n.push(a/b);
            }
        }
        return n.top();
    }
};

class Solution2 {
public:
    inline bool isNumber(const string& s)
    {
        if(s[0] == '-' && s.size() <= 1)
            return 0;
        int i = s[0] == '-' ? 1 : 0;
        for(; i < s.size(); i++)
            if(!isdigit(s[i]))
                return 0;
        return 1;
    }
    int evalRPN(vector<string>& tokens)
    {
        stack<int> opn;
        for(auto tok : tokens)
        {
            if(isNumber(tok))
            {
                opn.push(stoi(tok));
            }
            else
            {
                char op = tok[0];
                int b = opn.top(); opn.pop();
                int a = opn.top(); opn.pop();
                int c;
                switch(op)
                {
                    case '+':
                        c = a+b;
                    break;
                    case '-':
                        c = a-b;
                    break;
                    case '*':
                        c = a*b;
                    break;
                    case '/':
                        c = a/b;
                    break;
                }
                opn.push(c);
            }
        }
        return opn.top();
    }
};

int main()
{
    // skip
}
