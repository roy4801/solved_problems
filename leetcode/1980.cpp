/*
 * Leetcode Medium 1980. Find Unique Binary String
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
    string findDifferentBinaryString(vector<string>& nums)
    {
        int n = nums.size();
        int m = pow(2, n);
        set<string> dict(nums.begin(), nums.end());
        for(int i = 0; i < m; i++)
        {
            int tmp = i;
            string s;
            for(int i = 0; i < n; i++)
            {
                s += to_string(tmp & 1);
                tmp >>= 1;
            }
            reverse(s.begin(), s.end());
            
            if(!dict.count(s))
                return s;
        }
        return "";
    }
};

int main()
{
    // skip
}