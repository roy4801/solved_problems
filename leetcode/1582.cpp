/*
 * Leetcode Easy 1582. Special Positions in a Binary Matrix
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
    int numSpecial(vector<vector<int>>& mat)
    {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;

        vector<int> row(n), col(m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] != 1)
                    continue;

                if(row[i] == 1 && col[j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}
