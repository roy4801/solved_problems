/*
 * Leetcode Hard 239. Sliding Window Maximum
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

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k)
    {
        int n = v.size();
        vector<int> ans;
        deque<int> tmp;
        
        for(int i = 0; i < k; i++)
        {
            while(!tmp.empty() && v[i] > tmp.front())
            {
                tmp.pop_front();
            }
            tmp.push_front(v[i]);
        }
        ans.push_back(tmp.back());

        for(int i = k; i < n; i++)
        {
            // pop
            if(tmp.back() == v[i-k])
                tmp.pop_back();
            // push
            while(!tmp.empty() && v[i] > tmp.front())
            {
                tmp.pop_front();
            }
            tmp.push_front(v[i]);

            ans.push_back(tmp.back());
        }

        return ans;
    }
};

int main()
{
    int n, k = 50000;
    vector<int> v;
    v.reserve(100000);
    while(cin >> n)
    {
        v.push_back(n);
    }
    Solution{}.maxSlidingWindow(v, k);
}