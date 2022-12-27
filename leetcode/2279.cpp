/*
 * Leetcode Medium 2279. Maximum Split of Positive Even Integers
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
    int maximumBags(vector<int>& A, vector<int>& B, int n) {
        vector<int> N(A.size());
        for(int i = 0; i < A.size(); i++)
            N[i] = A[i] - B[i];
        sort(N.begin(), N.end());

        int ans = 0;
        for(int i = 0; i < N.size(); i++)
        {
            if(n >= N[i])
                n -= N[i], ans++;
        }
            
        return ans;
    }
};

int main()
{
    // skip
}