/*
 * Leetcode Easy 169. Majority Element
 * author: roy4801
 * AC(C++) 30ms 19.7MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

using P = pair<int, int>;

class Solution {
public:
    int normal(vector<int> &n)
    {
        map<int, int> m;
        for(int i : n)
        {
            if(!m.count(i)) m[i] = 0;
            m[i]++;
        }
        priority_queue<P> pq;
        for(auto &&[i, v] : m)
        {
            pq.push(make_pair(v, i));
        }
        return pq.top().second;
    }
    
    int follow_up_fucked_up(vector<int> &n)
    {
        int siz = n.size() / 2, cnt = 1;
        int acc = -1, ans = n[0];
        sort(n.begin(), n.end());
        
        for(int i = 1; i < n.size(); i++)
        {
            if(n[i] != n[i-1])
            {   
                if(cnt > acc)
                {
                    acc = cnt;
                    ans = n[i-1];
                }
                
                cnt = 1;
            }

            cnt++;
        }
        
        if(cnt > acc)
        {
            acc = cnt;
            ans = n.back();
        }
        
        
        return ans;
    }
    
    int majorityElement(vector<int>& nums)
    {
        return normal(nums);
    }
};

// Time: O(n) Space: O(n)
class Solution2 {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i : nums)
            m[i]++;
        int mi, mv = INT_MIN;
        for(auto [num, cnt] : m)
        {
            if(cnt > mv)
            {
                mv = cnt;
                mi = num;
            }
        }
        return mi;
    }
};

// Boyer-Moore Majority Vote Algorithm
// Time: O(n) Space: O(1)
class Solution3 {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int ans = nums[0], cnt = 1;
        for(int i = 1; i < n; i++)
        {
            if(ans == nums[i])
            {
                cnt++;
            }
            else if(cnt > 0)
            {
                cnt--;
            }
            else
            {
                ans = nums[i];
                cnt = 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {2,2,1,1,1,2,2};
    cout << Solution{}.normal(v) << '\n';
}