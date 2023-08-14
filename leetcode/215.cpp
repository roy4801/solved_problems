/*
 * Leetcode Medium 215. Kth Largest Element in an Array
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
    int findKthLargest(vector<int>& nums, int k)
    {
        int n = nums.size();
        priority_queue<int> pq;

        for(int i = 0; i < n; i++)
            pq.push(nums[i]);

        while(--k)
            pq.pop();

        return pq.top();
    }
};

int main()
{
    // skip
}
