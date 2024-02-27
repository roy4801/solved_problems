/*
 * Leetcode Easy 543. Diameter of Binary Tree
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
    int depth(TreeNode* r)
    {
        int ma = 0;
        if(r->left)
            ma = max(ma, depth(r->left)+1);
        if(r->right)
            ma = max(ma, depth(r->right)+1);
        return ma;
    }

    int ans = 0;
    void solve(TreeNode* r)
    {
        int tmp = 0;
        if(r->left)
            tmp += depth(r->left)+1;
        if(r->right)
            tmp += depth(r->right)+1;
        ans = max(ans, tmp);

        if(r->left) solve(r->left);
        if(r->right) solve(r->right);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        ans = 0;
        solve(root);
        return ans;
    }
};

int main()
{
    // skip
}
