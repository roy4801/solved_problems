/*
 * Leetcode Easy 1. Two Sum
 * author: roy4801
 * AC(C++) 31ms 15.4MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

#define N 10000

class Solution
{
public:
    vector<int> twoSum(vector<int>& n, int t)
    {
        vector<int> ans;
        map<int, vector<int>> m;
        set<int> used;

        for(int i = 0; i < n.size(); i++)
            m[n[i]].PB(i);

        for(int i = 0; i < n.size(); i++)
        {
            int val = n[i];
            used.insert(i);

            if(m.count(t-val))
            {
                for(int j : m[t-val])
                {
                    if(!used.count(j))
                    {
                        // printf(">> %d %d\n", i, j);
                        ans.PB(i);
                        ans.PB(j);
                        goto end;
                    }
                }
            }

            used.erase(i);
        }
end:
        return ans;
    }
};

// AC 9ms 16.5MB
using P = pair<int,int>;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        
        auto comp = [](const P& a, const P& b) { return a.first < b.first; };
        multiset<P, decltype(comp)> ns(comp); // num, idx
        for(int i = 0; i < n; i++)
            ns.emplace(nums[i], i);
        
        for(int i = 0; i < n; i++)
        {
            auto [a, b] = ns.equal_range({target - nums[i], -1});
            if(a != ns.end())
            {
                ans.push_back(i);
                for (auto it = a; it != b; it++)
                {
                    if(it->second != i)
                    {
                        ans.push_back(it->second);
                        return ans;
                    }
                }
            }
            ans.clear();
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        
        unordered_map<int,int> numToIdx; // num -> index
        for(int i = 0; i < n; i++)
        {
            int c = target - nums[i];
            if(numToIdx.count(c))
            {
                return {i, numToIdx[c]};
            }
            numToIdx[nums[i]] = i;
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {2,7,11,15};
    int t = 9;
    auto a = Solution{}.twoSum(v, t);
    DBG(a);
}
