/*
 * Leetcode Easy 501. Find Mode in Binary Search Tree
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
    void dfs(vector<int> &v, TreeNode *n)
    {
        if(n->left) dfs(v, n->left);
        v.push_back(n->val);
        if(n->right) dfs(v, n->right);
    }
    vector<int> findMode(TreeNode* r)
    {
        vector<int> v;
        dfs(v, r);

        map<int,int> m;
        for(int i : v)
            m[i]++;

        vector<pair<int,int>> rank;
        for(auto [k, v] : m)
            rank.push_back({v, k});
        sort(rank.begin(), rank.end(), greater<>());

        vector<int> ans;
        int tmp = -1;
        for(auto [a, b] : rank)
        {
            if(tmp == -1)
            {
                tmp = a;
                ans.push_back(b);
            }
            else if(tmp == a)
            {
                ans.push_back(b);
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
