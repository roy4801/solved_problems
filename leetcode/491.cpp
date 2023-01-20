/*
 * Leetcode Medium 491. Non-decreasing Subsequences
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
    bool check(vector<int> &v)
    {
        for(int i = 0; i < v.size()-1; i++)
        {
            if(v[i] > v[i+1])
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> findSubsequences(vector<int>& N)
    {
        int n = N.size(), upper = (int)pow(2, n)-1;
        vector<int> m;
        set<vector<int>> ans;
        m.reserve(n);

        for(int i = 1; i <= upper; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j))
                {
                    m.push_back(N[j]);
                }
            }
            // DBG(m);
            if(m.size() >= 2 && check(m))
            {
                ans.insert(m);
            }
            m.clear();
        }
        vector<vector<int>> tmp;
        copy(ans.begin(), ans.end(), tmp.begin());
        return tmp;
    }
};

class Solution2
{
public:
    vector<vector<int>> findSubsequences(vector<int>& N)
    {
        int n = N.size();
        set<vector<int>> ans;

        auto solve = [&](int i, bool pick, vector<int> m, auto &&solve) -> void
        {
            if(i >= n)
            {
                if(m.size() <= 1) goto end;

                for(int k = 0; k < m.size()-1; k++)
                {
                    if(m[k] > m[k+1])
                        goto end;        
                }

                ans.insert(m);
            end:
                return;
            }

            for(int j = 0; j <= 1; j++)
            {
                if(j)
                {
                    m.push_back(N[i]);
                }

                solve(i+1, j, m, solve);

                if(j)
                {
                    m.pop_back();
                }
            }
        };

        solve(0, 0, {}, solve);
        // DBG(ans);
        vector<vector<int>> tmp(ans.begin(), ans.end());
        return tmp;
    }
};

int main()
{
    vector<vector<int>> in = {
        {4,6,7,7},
        // {4,4,3,2,1},
    };
    for(auto &i : in)
    {
        // DBG(Solution{}.findSubsequences(i));
        DBG(Solution2{}.findSubsequences(i));
    }
}