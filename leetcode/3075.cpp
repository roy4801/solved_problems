/*
 * Leetcode Medium 3075. Maximize Happiness of Selected Children
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
    long long maximumHappinessSum(vector<int>& h, int k)
    {
        int n = h.size();
        LL ans = 0;
        priority_queue<int> pq;
        for(int i : h)
            pq.push(i);
        
        int i = 0;
        while(!pq.empty())
        {
            auto maxN = pq.top();
            pq.pop();

            if(i >= k)
                break;

            if(maxN - i <= 0)
                break;
            
            ans += maxN - i;
            i++;
        }
        return ans;
    }
};

using LL = long long;
class Solution2 {
public:
    long long maximumHappinessSum(vector<int>& h, int k)
    {
        int n = h.size();
        LL ans = 0;
        make_heap(h.begin(), h.end());
        
        int i = 0;
        while(!h.empty())
        {
            pop_heap(h.begin(), h.end());
            auto maxN = h.back();
            h.pop_back();

            if(i >= k)
                break;

            if(maxN - i <= 0)
                break;
            
            ans += maxN - i;
            i++;
        }
        return ans;
    }
};

int main()
{
    // skip
}