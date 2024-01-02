/*
 * Leetcode Medium 2610. Convert an Array Into a 2D Array With Conditions
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
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        
        list<pair<int,int>> s;
        map<int,int> m;
        for(int i = 0; i < n; i++)
            m[nums[i]]++;
        for(auto [i, cnt] : m)
            s.emplace_back(i, cnt);

        auto it = s.begin();
        vector<int> cur;
        while(!s.empty())
        {
            cur.push_back(it->first);
            it->second--;
            if(it->second <= 0)
            {
                it = s.erase(it);
            }
            else
            {
                it++;
            }

            if(it == s.end())
            {
                ans.push_back(cur);
                cur.clear();
                it = s.begin();
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
