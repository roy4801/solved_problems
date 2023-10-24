/*
 * Leetcode Medium 515. Find Largest Value in Each Tree Row
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
    vector<vector<int>> v;
    void dfs(TreeNode* n, int l)
    {
        if(n->left) dfs(n->left, l+1);
        if(n->right) dfs(n->right, l+1);
        if(l >= v.size())
            v.resize(l+1);
        v[l].push_back(n->val);
    }
    vector<int> largestValues(TreeNode* r)
    {
        if(!r) return {};
        vector<int> ans;
        dfs(r, 0);
        for(auto& i : v)
        {
            sort(i.begin(), i.end());
            ans.push_back(i.back());
        }
        return ans;
    }
};

int main()
{
    // skip
}
