/*
 * Leetcode Easy 566. Reshape the Matrix
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

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        vector<vector<int>> ans;
        int a = 0, b = 0;
        
        if(mat.size() * mat[0].size() != r * c)
            return mat;
        
        for(int i = 0; i < r; i++)
        {
            ans.emplace_back();
            for(int j = 0; j < c; j++)
            {
                ans[i].push_back(mat[a][b++]);
                if(b >= mat[a].size())
                {
                    a++;
                    b = 0;
                }
            }
        }
        
        return ans;
    }
};

int main()
{
}