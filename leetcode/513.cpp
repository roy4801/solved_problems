/*
 * Leetcode Medium 513. Find Bottom Left Tree Value
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
    int maxD = -1;
    int ans = -1;
    void solve(TreeNode* r, int depth)
    {
        if(depth > maxD)
        {
            maxD = depth;
            ans = r->val;
        }
        if(r->left) solve(r->left, depth+1);
        if(r->right) solve(r->right, depth+1);
    }
    int findBottomLeftValue(TreeNode* root)
    {
        solve(root, 0);
        return ans;
    }
};

int main()
{
    // skip
}