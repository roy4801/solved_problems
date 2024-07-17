/*
 * Leetcode Medium 1110. Delete Nodes And Return Forest
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
    set<TreeNode*> r; // all roots
    set<int> del; // to delete
    // right = n 是 par 的右還是左子節點
    void dfs(TreeNode* n, TreeNode* par, int right)
    {
        if(!n)
            return;

        if(del.count(n->val))
        {
            if(r.count(n))
                r.erase(n);

            if(right == 0)
                par->left = nullptr;
            else if(right == 1)
                par->right = nullptr;

            if(n->left)
                r.insert(n->left);
            if(n->right)
                r.insert(n->right);
        }

        dfs(n->left, n, 0);
        dfs(n->right, n, 1);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_del)
    {
        del = {to_del.begin(), to_del.end()};
        r.clear();
        r.insert(root);
        //
        dfs(root, nullptr, -1);
        return vector<TreeNode*>(r.begin(), r.end());
    }
};

int main()
{
    // skip
}