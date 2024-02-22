/*
 * Leetcode Easy 997. Find the Town Judge
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
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> i(n+1), o(n+1);
        for(auto& k : trust)
        {
            int a = k[0], b = k[1];
            i[b]++;
            o[a]++;
        }

        for(int a = 1; a <= n; a++)
        {
            if(o[a] == 0 && i[a] == n-1)
                return a;
        }

        return -1;
    }
};

int main()
{
    // skip
}
