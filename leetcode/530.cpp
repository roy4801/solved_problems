/*
 * Leetcode Easy 530. Minimum Absolute Difference in BST
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
    int getMinimumDifference(TreeNode* r)
    {
        vector<int> v;
        stack<TreeNode*> s({r});
        int ans = INT_MAX;

        while(!s.empty())
        {
            auto p = s.top(); s.pop();
            v.push_back(p->val);
            if(p->left) s.push(p->left);
            if(p->right) s.push(p->right);
        }

        sort(v.begin(), v.end());
        for(int i = 0; i < v.size()-1; i++)
        {
            ans = min(ans, abs(v[i]-v[i+1]));
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> v;
    void dfs(TreeNode* p)
    {
        if(p->left) dfs(p->left);
        v.push_back(p->val);
        if(p->right) dfs(p->right);
    }
    int getMinimumDifference(TreeNode* r)
    {
        int ans = INT_MAX;
        dfs(r);
        for(int i = 0; i < v.size()-1; i++)
            ans = min(ans, abs(v[i]-v[i+1]));
        return ans;
    }
};

int main()
{
    // skip
}
