/*
 * Leetcode Medium 74. Search a 2D Matrix
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
    bool searchMatrix(vector<vector<int>>& mat, int t)
    {
        auto bs = [&](int n, vector<int>& c) -> int
        {
            int l = 0, r = n;
            while(l < r)
            {
                int mid = l+(r-l)/2;
                if(c[mid] <= t)
                    l = mid + 1;
                else
                    r = mid;
            }
            return l;
        };

        vector<int> c;
        int n = mat.size(), m = mat[0].size();

        for(int i = 0; i < n; i++)
            c.push_back(mat[i][0]);

        int i = bs(n, c); // find row
        i--;
        if(i >= 0 && i <= n-1)
        {
            int j = bs(m, mat[i]); // find column
            j--;

            if(j >= 0 && j <= m-1)
            {
                return t == mat[i][j];
            }
        }

        return 0;
    }
};

int main()
{
    // skip
}
