/*
 * Leetcode Easy 404. Sum of Left Leaves
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
    inline static const bool IsLeaf(TreeNode* p)
    {
        return p && p->left == nullptr && p->right == nullptr;
    }
    inline static const bool IsLeftChild(TreeNode* par, TreeNode* ch)
    {
        return par && ch == par->left;
    }
    int solve(TreeNode* par, TreeNode* ch)
    {
        if(!ch) return 0;
        
        if (IsLeaf(ch) && IsLeftChild(par, ch))
            return ch->val;
        else
            return solve(ch, ch->left) + solve(ch, ch->right);
    }

    int sumOfLeftLeaves(TreeNode* r)
    {
        return solve(nullptr, r);
    }
};

int main()
{
    // skip
}