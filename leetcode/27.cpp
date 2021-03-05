/*
 * Leetcode Easy 27. Remove Element
 * author: roy4801
 * AC(C++) 0.000 8.8MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        return my(nums, val);
    }

    int my(vector<int> &nums, int val)
    {
        int n = nums.size();
        int del = 0;
        for (int i = 0; i < n-del; i++)
        {
            if(nums[i] == val)
            {
                del++;
                for(int j = i; j < n-1; j++)
                    nums[j] = nums[j+1];
                if(nums[i] == val)
                    i--;
            }
            
        }
        return n-del;
    }
};

int main()
{
    vector<int> v = {0, 1, 2, 2, 3, 0, 4, 2};
    printf("%d\n", Solution{}.removeElement(v, 2));
    print(v);
}