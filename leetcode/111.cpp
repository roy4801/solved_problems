/*
 * Leetcode Easy 111. Minimum Depth of Binary Tree
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
    using P=pair<TreeNode*, int>;
    queue<P> q;
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MAX;
        q.emplace(root, 1);
        while(!q.empty())
        {
            auto [cur, dep] = q.front(); q.pop();
            if(cur->left) q.emplace(cur->left, dep+1);
            if(cur->right) q.emplace(cur->right, dep+1);
            if(!cur->left && !cur->right)
                ans = min(ans, dep);
        }
        return ans;
    }
};

int main()
{
    // skip
}
