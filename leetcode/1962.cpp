/*
 * Leetcode Medium 1962. Remove Stones to Minimize the Total
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

class Solution1 {
public:
    int minStoneSum(vector<int>& N, int k) {
        priority_queue<int> pq(N.begin(), N.end());
        while(k--)
        {
            if(!pq.empty())
            {
                int a = pq.top(); pq.pop();
                a -= (int)floor(a / 2.0);
                pq.push(a);
            }
        }

        int ans = 0;
        while(!pq.empty())
            ans += pq.top(), pq.pop();
        return ans;
    }
};

class Solution2 {
public:
    int minStoneSum(vector<int>& N, int k) {
        make_heap(N.begin(), N.end());
        while(k--)
        {
            pop_heap(N.begin(), N.end());
            int tmp = (int)ceil(N.back()/2.0);
            N.pop_back();
            N.push_back(tmp);
            push_heap(N.begin(), N.end());
        }
        return accumulate(N.begin(), N.end(), 0);
    }
};

int main()
{
    // skip
}