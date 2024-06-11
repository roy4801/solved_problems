/*
 * Leetcode Easy 1122. Relative Sort Array
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
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b)
    {
        vector<int> ans;
        int n = a.size(), m = b.size();

        // 計算出現在 b 的數字出現次數， 不在 b 的數字直接推到答案
        map<int,int> cnt; // num -> count
        set<int> vis(b.begin(), b.end());
        for(int i : a)
        {
            if(vis.count(i))
                cnt[i]++;
            else
                ans.push_back(i);
        }

        // 按照 b 的順序，輸出答案陣列前半
        vector<int> tmp;
        for(int i : b)
        {
            for(int j = 0; j < cnt[i]; j++)
                tmp.push_back(i);
        }

        // 補上答案後半
        sort(ans.begin(), ans.end());
        ans.insert(ans.begin(), tmp.begin(), tmp.end());
        return ans;
    }
};

int main()
{
    // skip
}