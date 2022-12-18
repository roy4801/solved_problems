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

int main()
{
    // skip
}