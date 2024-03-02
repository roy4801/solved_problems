/*
 * Leetcode Medium 3066. Minimum Operations to Exceed Threshold Value II
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

using LL = long long;
class Solution {
public:
    int minOperations(vector<int>& in, int k)
    {
        int ans = 0;
        priority_queue<LL, vector<LL>, greater<>> pq(in.begin(), in.end());        
        LL a, b;
        while(pq.size() >= 2)
        {
            if(pq.top() >= k)
                break;

            ans++;
            
            a = pq.top();
            pq.pop();

            b = pq.top();
            pq.pop();
            
            LL c = a*2 + b;
            pq.push(c);   
        }
        return ans;
    }
};

int main()
{
    // skip
}