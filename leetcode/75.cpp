/*
 * Leetcode Medium 75. Sort Colors
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

// counting sort
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int cnt[3] = {0};
        int n = nums.size();
        for(int i = 0; i < n; i++)
            cnt[nums[i]]++;
        
        int k = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < cnt[i]; j++)
                nums[k++] = i;
    }
};

// Dutch National Flag algo
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();
        int a = 0, b = 0, c = n-1;

        while(b <= c)
        {
            if(nums[b] == 0)
            {
                swap(nums[a], nums[b]);
                a++;
                b++;
            }
            else if(nums[b] == 1)
            {
                b++;
            }
            else if(nums[b] == 2)
            {
                swap(nums[b], nums[c]);
                c--;
            }
        }
    }
};

int main()
{
    // skip
}