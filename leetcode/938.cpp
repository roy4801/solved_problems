/*
 * Leetcode Easy 938. Range Sum of BST
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int a, b, sum = 0;
    void solve(TreeNode* r)
    {
        if(!r) return;

        if(a <= r->val && r->val <= b)
            sum += r->val;

        solve(r->left);
        solve(r->right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        a = low, b = high;
        solve(root);
        return sum;
    }
};

class Solution2 {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return (root->left ? rangeSumBST(root->left, low, high) : 0) +
               (root->right ? rangeSumBST(root->right, low, high) : 0) +
               ((low <= root->val && root->val <= high) ? root->val : 0);
    }
};

int main()
{
	// skip
}
