/*
 * Leetcode Medium 826. Most Profit Assigning Work
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

using P=pair<int,int>;
class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w)
    {
        int n = d.size(), m = w.size();

        // sort
        vector<P> v;
        for(int i = 0; i < n; i++)
            v.emplace_back(d[i], p[i]);
        sort(v.begin(), v.end());

        // 還原成獨立陣列，方便 lower_bound
        for(int i = 0; i < n; i++)
        {
            d[i] = v[i].first;
            p[i] = v[i].second;
        }

        // 對於難度 d[i] 可以挑的最大數字 max(p[0], ... ,p[i])
        for(int i = 1; i < n; i++)
            p[i] = max(p[i], p[i-1]);
        // 同樣難度，可以挑最大的數字
        for(int i = n-1; i >= 1; i--)
            if(d[i-1] == d[i])
                p[i-1] = p[i];

        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            // 找大於等於 w[i] 的第一個難度
            int j = lower_bound(d.begin(), d.end(), w[i]) - d.begin();
            // 如果不相同 代表會找到右界+1 (也代表 w[i] 不在 d 中)
            if(d[j] != w[i])
            {
                if(j-1 >= 0)
                {
                    ans += p[j-1];
                }
            }
            else
            {
                ans += p[j];
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}