/*
 * Leetcode Easy 3079. Find the Sum of Encrypted Integers
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
    int encrypt(int n)
    {
        int tmp = n, i = 0, d = 0;
        while(tmp)
        {
            i = max(i, tmp % 10);
            tmp /= 10;
            d++;
        }

        n = 0;
        for(int j = 0; j < d; j++)
        {
            n *= 10;
            n += i;
        }
        return n;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            nums[i] = encrypt(nums[i]);
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main()
{
    // skip
}