/*
 * Leetcode Easy 104. Maximum Depth of Binary Tree
 * author: roy4801
 * AC(C++) 18ms 18.9MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "leetcode_helper.h"
#include "helper.h"

class Solution {
public:
    int dfs(int n, TreeNode *t)
    {
        int ans = n;
        
        if(!t)
            return ans;

        if(t->left)
            ans = max(ans, dfs(n+1, t->left));
        
        if(t->right)
            ans = max(ans, dfs(n+1, t->right));
        
        return ans;
    }

    // Iterative ref: https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/34238/Clean-Java-Iterative-Solution
    int bfs(TreeNode *t)
    {
        stack<TreeNode*> s;
        s.push(t);
        int cnt = 0;

        while(!s.empty())
        {
            int siz = s.size();
            while(siz > 0)
            {
                TreeNode *now = s.top(); s.pop();
                if(now->left)
                    s.push(now->left);
                if(now->right)
                    s.push(now->right);
                siz--;
            }
            cnt++;
        }

        return cnt;
    }
    
    int maxDepth(TreeNode* root)
    {
        return root ? dfs(1, root) : 0;
        // return root ? bfs(root) : 0;
    }
};

int main()
{
    vector<int> v = {3, 9, 20, TREE_NULL, TREE_NULL, 15,7};
    TreeNode *r = new TreeNode;
    build_tree(r, v, 0);
    std::cout << Solution{}.maxDepth(r) << '\n';
}