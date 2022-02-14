#pragma once
#ifndef LEETCODE_HELPER_H_
#define LEETCODE_HELPER_H_

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int TREE_NULL = 999;

#define TREE_LEFT(x) (((x)<<2)+1)
#define TREE_RIGHT(x) (((x)<<2)+2)

template<typename T>
void build_tree(TreeNode *r, const std::vector<T> &v, int idx)
{
    r->val = v[idx];   

    int i = TREE_LEFT(idx);
    if(i < v.size() && v[i] != TREE_NULL)
    {
        r->left = new TreeNode;
        build_tree(r->left, v, i);
    }

    i = TREE_RIGHT(idx);
    if(i < v.size() && v[i] != TREE_NULL)
    {
        r->right = new TreeNode;
        build_tree(r->right, v, i);
    }
}

#endif
