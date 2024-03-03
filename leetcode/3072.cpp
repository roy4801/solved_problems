/*
 * Leetcode Hard 3072. Distribute Elements Into Two Arrays II
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
    int up(vector<int>& v, int val)
    {
        auto it = upper_bound(v.begin(), v.end(), val);
        return distance(v.begin(), it);
    }
    void insert(vector<int>& v, int val, vector<int>& vv)
    {
        auto it = lower_bound(v.begin(), v.end(), val);
        v.insert(it, val);
        vv.push_back(val);
    }
    vector<int> resultArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> a = {nums[0]}, b = {nums[1]};
        vector<int> aa = a, bb = b;
        
        for(int i = 2; i < n; i++)
        {
            int A = a.size() - up(a, nums[i]);
            int B = b.size() - up(b, nums[i]);
            
            if(A > B)
            {
                insert(a, nums[i], aa);
            }
            else if(A < B)
            {
                insert(b, nums[i], bb);
            }
            else if(A == B)
            {
                if(a.size() < b.size())
                {
                    insert(a, nums[i], aa);
                }
                else if(a.size() > b.size())
                {
                    insert(b, nums[i], bb);
                }
                else
                {
                    insert(a, nums[i], aa);
                }
            }
        }
        
        vector<int> ans;
        ans.insert(ans.end(), aa.begin(), aa.end());
        ans.insert(ans.end(), bb.begin(), bb.end());
        return ans;
    }
};

int main()
{
    // skip
}