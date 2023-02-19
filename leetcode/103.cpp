/*
 * Leetcode Medium 103. Binary Tree Zigzag Level Order Traversal
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution {
public:
    map<int, vector<int>> ans;

    void solve(TreeNode *s, int dep)
    {
        if(!s) return;

        if(!ans.count(dep))
            ans[dep] = {};
        ans[dep].push_back(s->val);

        solve(s->left, dep+1);
        solve(s->right, dep+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* r) {
        vector<vector<int>> answer;
        solve(r, 0);

        int i = 0;
        for(auto &&[a, b] : ans)
        {
            if(i % 2 != 0)
                reverse(b.begin(), b.end());
            answer.push_back(b);

            i++;
        }
        return answer;
    }
};
int main()
{
    vector<vector<int>> in = {
        {3, 9, 20, -1, -1, 15, 7},
        {1},
    };
    for(auto &i : in)
    {
        TreeNode *r = new TreeNode;
        build_tree(r, i, 0, -1);
        DBG(Solution{}.zigzagLevelOrder(r));
    }
}