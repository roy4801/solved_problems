/*
 * Leetcode Easy 225. Implement Stack using Queues
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

class MyStack {
public:
    MyStack() {
        a = {};
        b = {};
    }

    void push(int x) {
        a.push(x);
    }

    int pop() {
        int n = a.size()-1;
        bool flag = false;
        if(n != 0)
            flag = true;
        while(n--)
        {
            b.push(a.front());
            a.pop();
        }
        int res = a.back();
        a.pop();
        if(flag)
        {
            a = b;
            b = {};
        }
        return res;
    }

    int top() {
        return a.back();
    }

    bool empty() {
        return a.empty();
    }
private:
    queue<int> a, b;
};

int main()
{
    // skip
}
