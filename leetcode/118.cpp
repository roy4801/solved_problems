/*
 * Leetcode Easy 118. Pascal's Triangle
 * author: roy4801
 * AC(C++)
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
    vector<vector<int>> ans;
    vector<vector<int>> generate(int n)
    {
        if(n >= 1)
            ans.emplace_back(vector<int>{1});
        if(n >= 2)
            ans.emplace_back(vector<int>{1, 1});
        
        for(int i = 2; i < n; i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(int j = 0; j < ans[i-1].size()-1; j++)
            {
                tmp.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans;
        for(int i = 1; i <= n; i++)
        {
            ans.push_back(vector<int>(i));
            auto &cur = ans.back();
            cur[0] = 1;
            if(n >= 2)
            {
                cur[i-1] = 1;

                auto &prev = *(ans.end()-2);
                for(int j = 1; j <= i-2; j++)
                    cur[j] = prev[j] + prev[j-1];
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
