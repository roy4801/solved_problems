#pragma once
#ifndef LEETCODE_HELPER_H_
#define LEETCODE_HELPER_H_

#include <iostream>
#include <string>
#include <vector>

// TODO: Add print list

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* build_sll(const std::vector<int> &v)
{
    ListNode *head = nullptr, *cur = nullptr, *prev = nullptr;
    for(auto i : v)
    {
        cur = new ListNode;
        if(prev) prev->next = cur;
        if(!head) head = cur;
        cur->val = i;
        prev = cur;
    }
    return head;
}

// void print_list

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#endif
