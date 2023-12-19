/*
 * Leetcode Easy 661. Image Smoother
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
    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        int n = img.size(), m = img[0].size();
        auto calc = [&](int i, int j)
        {
            double sum = 0.0;
            int cnt = 0;
            for(int a = i-1; a <= i+1; a++)
            {
                for(int b = j-1; b <= j+1; b++)
                {
                    if(0 <= a && a < n &&
                       0 <= b && b < m)
                    {
                        sum += img[a][b];
                        cnt++;
                    }
                }
            }
            return floor(sum/max(cnt, 1));
        };

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans[i][j] = calc(i, j);

        return ans;
    }
};

int main()
{
    // skip
}
