/*
 * Leetcode Easy 703. Kth Largest Element in a Stream
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

class KthLargest {
public:
    KthLargest(int k, vector<int>& v)
    {
        this->k = k;
        for(int i = 0; i < v.size(); i++)
        {
            add(v[i]);
        }
    }
    
    int add(int val)
    {
        if(!pq.empty() && pq.size() >= k)
        {
            if(val > pq.top())
            {
                pq.pop();
                pq.push(val);
            }
        }
        else
        {
            pq.push(val);
        }
        return pq.top();
    }

    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
};

class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int _k, vector<int>& nums)
    {
        k = _k;
        for(int i : nums)
            add(i);
    }
    
    inline int add(int val) 
    {
        if(pq.size() >= k)
        {
            if(pq.top() < val)
            {
                pq.pop();
                pq.push(val);
            }
        }
        else
        {
            pq.push(val);
        }
        return pq.top();
    }
};

int main()
{
    vector<int> v = {4, 5, 8, 2};
    KthLargest sol(3, v);
    DBG(sol.add(3));
    DBG(sol.add(5));
    DBG(sol.add(10));
    DBG(sol.add(9));
    DBG(sol.add(4));
}