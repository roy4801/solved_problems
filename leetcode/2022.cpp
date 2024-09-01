/*
 * Leetcode Easy 2022. Convert 1D Array Into 2D Array
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
    vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n)
    {
        vector<vector<int>> ans(m, vector<int>(n));
        if(m*n != arr.size())
            return {};

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans[i][j] = arr[i*n+j];

        return ans;
    }
};

int main()
{
    // skip
}