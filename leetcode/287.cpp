/*
 * Leetcode Medium 287. Find the Duplicate Number
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

// hashmap
class Solution1 {
public:
    int findDuplicate(vector<int>& nums)
    {
        unordered_set<int> s;
        for(int i : nums)
        {
            if(!s.count(i))
                s.insert(i);
            else
                return i;
        }
        return -1;
    }
};

// sort
class Solution2 {
public:
    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1])
                return nums[i];
        }
        return -1;
    }
};

// floyd's tortoise and hare
class Solution3 {
public:
    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        int a = 0, b = 0; // a=tortise, b=hare
        do
        {
            a = nums[a];
            b = nums[nums[b]];
        }
        while(a != b);
        // find start point
        a = 0;
        while(a != b)
        {
            a = nums[a];
            b = nums[b];
        }
        return b;
    }
};

int main()
{
    // skip
}