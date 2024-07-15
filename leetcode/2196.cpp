/*
 * Leetcode Medium 2196. Create Binary Tree From Descriptions
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

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
    // map<int, TreeNode*> M; // id, mem
    TreeNode* M[100005];
    // map<int, bool> vis;
    unordered_set<int> N;
    TreeNode* createBinaryTree(vector<vector<int>>& des)
    {
        int p, c, l; // parent, child, isLeft

        for(auto &i : des)
        {
            p = i[0];   
            N.insert(p);
        }

        for(auto &i : des)
        {
            p = i[0], c = i[1], l = i[2];

            if(!M[p])
                M[p] = new TreeNode(p);
            if(!M[c])
                M[c] = new TreeNode(c);

            N.erase(c);

            // isLeft
            if(l)
                M[p]->left = M[c];
            else
                M[p]->right = M[c];
        }
        
        return M[*N.begin()];
    }
};

class Solution2 {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc)
    {
        unordered_map<int, int> in; // in degree
        unordered_map<int, TreeNode*> m; // val -> node

        for(auto& it : desc)
        {
            int a = it[0], b = it[1], left = it[2];
            if(!m.count(a))
            {
                m[a] = new TreeNode(a);
                in[a] = 0;
            }
            if(!m.count(b))
            {
                m[b] = new TreeNode(b);
                in[b] = 0;
            }
            if(left)
            {
                m[a]->left = m[b];
            }
            else
            {
                m[a]->right = m[b];
            }
            in[b]++;
        }
        
        TreeNode* ans = nullptr;
        for(auto [i, deg] : in)
        {
            if(deg == 0)
            {
                ans = m[i];
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    TreeNode *ans = Solution{}.createBinaryTree(v);
    printf("%p\n", ans);

    DBG(ans);
}