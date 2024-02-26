/*
 * Leetcode Easy 100. Same Tree
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
    bool isSameStruct(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
            return 1;
        if((p && !q) || (!p && q))
            return 0;
        if(p && q && p->val != q->val)
            return 0;

        if(!isSameStruct(p->left, q->left))
            return 0;
        if(!isSameStruct(p->right, q->right))
            return 0;

        return 1;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q)
            return p == q;
        return isSameStruct(p, q);
    }
};

int main()
{
    // skip
}
