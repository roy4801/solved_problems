/*
 * Leetcode Medium 77. Combinations
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
    int n, k;
    vector<vector<int>> ans;
    vector<int> tmp;
    // st=數字, cnt=長度
    void solve(int st, int cnt)
    {
        if(cnt > k)
        {
            ans.push_back(vector<int>(tmp.begin()+1, tmp.begin()+k+1));
            return;
        }
        // 枚舉從 [st, n]
        for(int i = st; i <= n; i++)
        {
            tmp[cnt] = i;
            solve(i+1, cnt+1);
        }
    }

    vector<vector<int>> combine(int _n, int _k)
    {
        n = _n;
        k = _k;
        tmp.resize(n+5);
        solve(1, 1);
        return ans;
    }
};

int main()
{

}
