/*
 * Leetcode Medium 155. Min Stack
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

class MinStack
{
public:
    MinStack() 
    {    
    }
    
    void push(int val)
    {
        if(s.empty())
        {
            s.push({val, val});
        }
        else
        {
            int m = min(val, s.top().Y);
            s.push({val, m});
        }
    }
    
    void pop()
    {
        s.pop();
    }
    
    int top()
    {
        return s.top().X;
    }
    
    int getMin()
    {
        return s.top().Y;
    }

    stack<P> s; // value, min
};


int main()
{

}
