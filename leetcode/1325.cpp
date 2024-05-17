/*
 * Leetcode Medium 1325. Delete Leaves With a Given Value
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

#define OK(n) (!n->left && !n->right && n->val == t)
#define Remove_N() {         \
    if(lr == 1)              \
        par->left = nullptr; \
    else if(lr == 2)         \
        par->right = nullptr;\
    }

class Solution {
public:
    int t;
    // 1 = left, 2 = right
    void dfs(TreeNode* par, TreeNode* n, int lr)
    {
        if(!n)
            return;

        if(OK(n))
            Remove_N();

        dfs(n, n->left, 1);
        dfs(n, n->right, 2);

        if(OK(n))
            Remove_N();
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        t = target;
        dfs(nullptr, root, 0);
        if(OK(root))
            root = nullptr;
        return root;
    }
};

int main()
{
    // skip
}