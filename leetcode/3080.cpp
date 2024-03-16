/*
 * Leetcode Medium 3080. Mark Elements on Array by Performing Queries
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

using LL=long long;
using P=pair<LL,int>; // value, index
#define X first
#define Y second
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& q)
    {
        int n = nums.size(), m = q.size();
        set<P> mark;
        vector<LL> ans(m);
        
        priority_queue<P,vector<P>,greater<>> pq;
        for(int i = 0; i < n; i++)
            pq.emplace(nums[i], i);
        
        LL sum = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i = 0; i < m; i++)
        {
            int qi = q[i][0], k = q[i][1];
            if(!mark.count({nums[qi], qi}))
            {
                mark.emplace(nums[qi], qi);
                sum -= nums[qi];
            }
            
            for(int j = 0; j < k; )
            {
                if(!pq.empty())
                {
                    auto sm = pq.top();
                    pq.pop();
                
                    if(!mark.count(sm))
                    {
                        sum -= sm.X;
                        mark.insert(sm);
                        j++;
                    }
                }
                else
                {
                    j++;
                    continue;
                }
            }
            
            ans[i] = sum;
        }
        
        return ans;
    }
};

int main()
{
    // skip
}