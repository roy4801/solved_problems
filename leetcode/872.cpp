/*
 * Leetcode Easy 872. Leaf-Similar Trees
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
    void leaf(TreeNode* r, vector<int>& v)
    {
        if(!r->left && !r->right)
            v.push_back(r->val);
        if(r->left) leaf(r->left, v);
        if(r->right) leaf(r->right, v);
    }
    bool leafSimilar(TreeNode* r1, TreeNode* r2)
    {
        vector<int> a, b;
        leaf(r1, a);
        leaf(r2, b);
        return a == b;
    }
};

int main()
{
    // skip
}
