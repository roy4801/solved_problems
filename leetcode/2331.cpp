/*
 * Leetcode Easy 2331. Evaluate Boolean Binary Tree
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
    bool evaluateTree(TreeNode* n)
    {
        if(!n->left && !n->right)
            return n->val;

        if(n->val == 2)
            return evaluateTree(n->left) | evaluateTree(n->right);
        else if(n->val == 3)
            return evaluateTree(n->left) & evaluateTree(n->right);

        return 0;
    }
};

int main()
{
    // skip
}
