/*
 * Leetcode Easy 144. Binary Tree Preorder Traversal
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
    void dfs(TreeNode* s)
    {
        if(!s) return;
        ans.push_back(s->val);

        if(s->left) dfs(s->left);
        if(s->right) dfs(s->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;   
    }
};

int main()
{
    // skip
}