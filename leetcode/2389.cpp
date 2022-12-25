/*
 * Leetcode Easy 2389. Longest Subsequence With Limited Sum
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
    vector<int> answerQueries(vector<int>& N, vector<int>& Q)
    {
        vector<int> ans;
        sort(N.begin(), N.end());

        for(int q : Q)
        {
            int acc = 0, cnt = 0;
            for(int n : N)
            {
                if(acc + n <= q)
                    acc += n, cnt++;
                else
                    break;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main()
{
    // skip
}