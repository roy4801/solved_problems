/*
 * Leetcode Easy 1046. Last Stone Weight
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

class Solution {
public:
    int lastStoneWeight(vector<int>& s)
    {
        priority_queue<int> pq(s.begin(), s.end());
        while(pq.size() > 1)
        {
            if(pq.size() >= 2)
            {
                int a = pq.top(); pq.pop();
                int b = pq.top(); pq.pop();
                if(a != b)
                {
                    pq.push(a-b);
                }
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main()
{
    // skip
}
