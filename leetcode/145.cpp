/*
 * Leetcode Easy 145. Binary Tree Postorder Traversal
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
    vector<int> ans;
    void solve(TreeNode *r)
    {
        if(!r) return;
        if(r->left) solve(r->left);
        if(r->right) solve(r->right);
        ans.push_back(r->val);
    }
    vector<int> postorderTraversal(TreeNode* r) {
        ans.clear();
        solve(r);
        return ans;
    }
};

int main()
{
    // skip
}