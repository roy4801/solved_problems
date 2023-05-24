/*
 * Leetcode Medium 2542. Maximum Subsequence Score
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

using LL=long long;
using P=pair<int, int>;
#define X first
#define Y second
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k)
    {
        int n = a.size();
        vector<P> v;
        for(int i = 0; i < n; i++)
            v.emplace_back(b[i], a[i]);
        sort(v.begin(), v.end(), greater<P>());

        LL ans = INT_MIN, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++)
        {
            // top-k heap
            if(!pq.empty() && pq.size() >= k)
            {
                if(pq.top() < v[i].Y)
                {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(v[i].Y);
                    sum += v[i].Y;
                }
            }
            else
            {
                pq.push(v[i].Y);
                sum += v[i].Y;
            }

            if(i >= k-1)
            {
                ans = max(ans, sum*v[i].X);
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}