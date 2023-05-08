/*
 * Leetcode Easy 1572. Matrix Diagonal Sum
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
    int diagonalSum(vector<vector<int>>& mat)
    {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;

        for(int i = 0, j = 0; i < n && j < m; i++, j++)
        {
            ans += mat[i][j];
        }
        for(int i = 0, j = m-1; i < n && j >= 0; i++, j--)
        {
            ans += mat[i][j];
        }
        return ans;
    }
};

int main()
{
    // skip
}
