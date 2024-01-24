/*
 * Leetcode Medium 1457. Pseudo-Palindromic Paths in a Binary Tree
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
    vector<int> s; // path
    map<int, int> cnt; // num -> exist count
    int ans = 0;
    void dfs(TreeNode* r)
    {
        // do
        s.push_back(r->val);
        cnt[r->val]++;

        // dfs
        if(r->left)
            dfs(r->left);
        if(r->right)
            dfs(r->right);

        // is leaf node
        if(!r->left && !r->right)
        {
            int oddCnt = 0;
            for(auto [num, c] : cnt)
                if(c % 2 != 0)
                    oddCnt++;
            
            if(s.size() % 2 != 0)
            {
                if(oddCnt <= 1)
                    ans++;
            }
            else
            {
                if(oddCnt == 0)
                    ans++;
            }
        }
        
        // undo
        s.pop_back();
        cnt[r->val]--;
        if(cnt[r->val] == 0)
            cnt.erase(r->val);
    }
    int pseudoPalindromicPaths (TreeNode* root)
    {
        ans = 0;
        s.clear();
        dfs(root);
        return ans;
    }
};

int main()
{
    // skip
}