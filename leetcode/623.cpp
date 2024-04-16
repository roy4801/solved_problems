/*
 * Leetcode Medium 623. Add One Row to Tree
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

// recursive space O(n)
class Solution {
public:
    map<int, vector<TreeNode*>> d2n; // depth -> {node...}
    map<TreeNode*,TreeNode*> par;
    void build(TreeNode* p, int depth)
    {
        d2n[depth].push_back(p);
        if(p->left)
            build(p->left, depth+1);
        if(p->right)
            build(p->right, depth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if(depth == 1)
        {
            auto n = new TreeNode(val, root, nullptr);
            return n;
        }
        d2n.clear();
        build(root, 1);

        for(auto p : d2n[depth-1])
        {
            auto parent = p;
            auto l = parent->left;
            auto r = parent->right;
            auto nl = new TreeNode(val, l, nullptr);
            auto nr = new TreeNode(val, nullptr, r);
            parent->left = nl;
            parent->right = nr;
        }

        return root;
    }
};

// recursive space O(1)
class Solution {
public:
    int depth, val;
    void solve(TreeNode* p, int d)
    {
        if(d+1 == depth)
        {
            auto l = p->left, r = p->right;
            p->left = new TreeNode(val, l, nullptr);
            p->right = new TreeNode(val, nullptr, r);
        }
        if(p->left) solve(p->left, d+1);
        if(p->right) solve(p->right, d+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        this->depth = depth;
        this->val = val;
        if(depth == 1)
        {
            auto n = new TreeNode(val, root, nullptr);
            return n;
        }

        solve(root, 1);
        return root;
    }
};

// iteratively space O(1)
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if(depth == 1)
        {
            auto n = new TreeNode(val, root, nullptr);
            return n;
        }

        stack<pair<TreeNode*,int>> s;
        s.emplace(root, 1);
        while(!s.empty())
        {
            auto [p, d] = s.top();
            s.pop();

            if(d+1 == depth)
            {
                auto l = p->left, r = p->right;
                p->left = new TreeNode(val, l, nullptr);
                p->right = new TreeNode(val, nullptr, r);
            }
            if(p->left) s.emplace(p->left, d+1);
            if(p->right) s.emplace(p->right, d+1);
        }
        return root;
    }
};

int main()
{
    // skip
}
