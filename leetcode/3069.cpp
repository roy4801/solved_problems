/*
 * Leetcode Easy 3069. Distribute Elements Into Two Arrays I
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
    vector<int> resultArray(vector<int>& nums)
    {
        vector<int> ans;
        vector<int> a, b;
        for(int i : nums)
        {
            if(a.empty())
                a.push_back(i);
            else if(b.empty())
                b.push_back(i);
            else
            {
                if(a.back() > b.back())
                    a.push_back(i);
                else
                    b.push_back(i);
            }
        }
        ans.insert(ans.end(), a.begin(), a.end());
        ans.insert(ans.end(), b.begin(), b.end());
        return ans;
    }
};

int main()
{
    // skip
}