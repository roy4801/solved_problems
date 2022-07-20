/*
 * Leetcode Easy 119. Pascal's Triangle II
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution {
public:
    vector<int> ans;
    vector<int> getRow(int r)
    {
        ans.push_back(1);
        
        for(int i = 0; i < r; i++)
        {  
            if(i >= 1)
            {
                for(int j = ans.size()-1; j >= 1; j--)
                {
                    ans[j] += ans[j-1];
                }
            }
            ans.push_back(1);
        }
        return ans;
    }
};

int main()
{
    // skip
}