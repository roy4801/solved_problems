/*
 * Leetcode Medium 1161. Maximum Level Sum of a Binary Tree
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

using T=tuple<TreeNode*, int>; // node, depth, sum
class Solution {
public:
    int maxLevelSum(TreeNode* r)
    {
        int sum[1000] = {0}; // sum[i] = sum of depth i
        int maxDep = -1;
        queue<T> q;
        q.emplace(r, 1);

        while(!q.empty())
        {
            auto [p, dep] = q.front(); q.pop();
            sum[dep] += p->val;
            maxDep = max(maxDep, dep);
            if(p->left)
                q.emplace(p->left, dep+1);
            if(p->right)
                q.emplace(p->right, dep+1);
        }

        return max_element(sum+1, sum+maxDep+1)-sum;
    }
};

int main()
{
    // skip
}
