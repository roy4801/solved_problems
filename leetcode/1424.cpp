/*
 * Leetcode Medium 1424. Diagonal Traverse II
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

using P = tuple<int,int,int>;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v)
    {
        int n = v.size(), m = v[0].size();
        vector<int> ans;

        vector<P> tmp; // sum, j, i
        for(int i = 0; i < n; i++)
            for(int j = 0; j < v[i].size(); j++)
                tmp.push_back({i+j, j, i});
        sort(tmp.begin(), tmp.end());

        for(auto [sum, j, i] : tmp)
            ans.push_back(v[i][j]);

        return ans;
    }
};

int main()
{
    // skip
}
