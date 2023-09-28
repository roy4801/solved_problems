/*
 * Leetcode Easy 905. Sort Array By Parity
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& n)
	{
        sort(n.begin(), n.end(), [](int a, int b) {
        	return a % 2 == 0 && b % 2 != 0;
        });
        return n;
    }
};

class Solution2 {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        while(i < n && nums[i] % 2 == 0)
            i++;

        for(int j = i+1; j < n; j++)
        {
            if(nums[j] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        return nums;
    }
};

int main()
{
	vector<int> v = {3,1,2,4};
	DBG(Solution{}.sortArrayByParity(v));
}
