/*
 * Leetcode Medium 1609. Even Odd Tree
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
    vector<vector<int>> v; // [depth] = {nums, ...}
    void dfs(TreeNode* r, int depth)
    {
        if(v.size() <= depth)
            v.resize(depth+1);
        v[depth].push_back(r->val);
        if(r->left) dfs(r->left, depth+1);
        if(r->right) dfs(r->right, depth+1);
    }
    bool evenOk(vector<int>& a)
    {
        if(any_of(a.begin(), a.end(), [](int k){ return k%2 != 0; }))
            return 0;
        for(int i = 1; i < a.size(); i++)
            if(a[i-1] <= a[i])
                return 0;
        return 1;
    }
    bool oddOk(vector<int>& a)
    {
        if(any_of(a.begin(), a.end(), [](int k){ return k%2 == 0; }))
            return 0;
        for(int i = 1; i < a.size(); i++)
            if(a[i-1] >= a[i])
                return 0;
        return 1;
    }
    bool isEvenOddTree(TreeNode* root)
    {
        dfs(root, 0);
        for(int d = 0; d < v.size(); d++)
        {
            if(d % 2 != 0 && !evenOk(v[d]))
                return 0;
            if(d % 2 == 0 && !oddOk(v[d]))
                return 0;
        }
        return 1;
    }
};

int main()
{
    // skip
}