/*
 * Leetcode Medium 2433. Find The Original Array of Prefix Xor
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
    vector<int> findArray(vector<int>& pref)
    {
        int n = pref.size();
        vector<int> ans = {pref[0]};

        int tmp = ans[0];
        for(int i = 1; i < n; i++)
        {
            tmp ^= pref[i];
            ans.push_back(tmp);
            tmp ^= pref[i];
            tmp ^= ans.back();
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> findArray(vector<int>& pref)
    {
        int n = pref.size();
        vector<int> ans = {pref[0]};
        for(int i = 1; i < n; i++)
        {
            ans.push_back(pref[i]^pref[i-1]);
        }

        return ans;
    }
};

int main()
{
    // skip
}
