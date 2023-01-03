/*
 * Leetcode Easy 944. Delete Columns to Make Sorted
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
    int minDeletionSize(vector<string>& v) {
        int cnt = 0;
        int n = v.size(), m = v[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n-1; j++)
            {
                char a = v[j][i], b = v[j+1][i];
                if(a > b)
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<string>> v = {
        {"cba","daf","ghi"},
        {"a","b"},
        {"zyx","wvu","tsr"},
    };
    for(auto &i : v)
    {
        DBG(Solution{}.minDeletionSize(i));
    }
}