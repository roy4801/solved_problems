/*
 * Leetcode Medium 6018. Create Binary Tree From Descriptions
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

int main()
{
    vector<vector<int>> v = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    TreeNode *ans = Solution{}.createBinaryTree(v);
    printf("%p\n", ans);

    DBG(ans);
}