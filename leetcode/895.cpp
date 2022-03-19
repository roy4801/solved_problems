/*
 * Leetcode Hard 895. Maximum Frequency Stack
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

class FreqStack
{
public:
    priority_queue<tuple<int, int, int>> pq; // 第幾個, pos, val
    map<int, int> m; // val -> freq
    int pos = 0;
    
    FreqStack()
    {
    }
    
    void push(int val)
    {
        pq.emplace(++m[val], pos++, val);
    }
    
    int pop()
    {
        auto [freq, pos, val] = pq.top(); pq.pop();
        m[val]--;
        return val;
    }
};


int main()
{
    FreqStack* a = new FreqStack();
    a->push(5); // The stack is [5]
    a->push(7); // The stack is [5,7]
    a->push(5); // The stack is [5,7,5]
    a->push(7); // The stack is [5,7,5,7]
    a->push(4); // The stack is [5,7,5,7,4]
    a->push(5); // The stack is [5,7,5,7,4,5]
    // puts("FUCK");
    DBG(a->pop());   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    DBG(a->pop());   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    DBG(a->pop());   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    DBG(a->pop());   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The 
}