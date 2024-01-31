/*
 * Leetcode Medium 739. Daily Temperatures
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
#define F first
#define S second

class Solution {
public:
    stack<pair<int, int>> s; // idx, temp
    vector<int> ans;
    vector<int> dailyTemperatures(vector<int>& temp)
    {
        ans.resize(temp.size(), 0);
        s.push(make_pair(0, temp[0]));
        for(int i = 0; i < temp.size(); i++)
        {
            while(!s.empty() && s.top().S < temp[i])
            {
                ans[s.top().F] = i - s.top().F;
                s.pop();
            }
            s.push(make_pair(i, temp[i]));
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temp)
    {
        int n = temp.size();
        stack<pair<int,int>> s; // val, idx
        // desecnding
        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            while(!s.empty())
            {
                auto [val, idx] = s.top();
                if(temp[i] > val)
                {
                    ans[idx] = i - idx;
                    s.pop();
                }
                else
                    break;
            }

            s.push({temp[i], i});
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {73,74,75,71,69,72,76,73};
    DBG(Solution{}.dailyTemperatures(v));
}
