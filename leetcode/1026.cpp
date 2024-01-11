/*
 * Leetcode Medium 1026. Maximum Difference Between Node and Ancestor
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
    int solve(TreeNode* r, int a, int b)
    {
        a = min(a, r->val);
        b = max(b, r->val);

        if(!r->left && !r->right)
            return b-a;

        int ans = -1;
        if(r->left)
            ans = max(ans, solve(r->left, a, b));
        if(r->right)
            ans = max(ans, solve(r->right, a, b));
        return ans;
    }
    int maxAncestorDiff(TreeNode* root)
    {
        return solve(root, INT_MAX, INT_MIN);
    }
};

int main()
{
    // skip
}
