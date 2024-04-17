/*
 * Leetcode Medium 988. Smallest String Starting From Leaf
 * author: roy4801
 * (C++)
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
    string s;
    string ans;
    void solve(TreeNode* r)
    {
        if(!r) return;

        s += 'a'+r->val;

        if(!r->left && !r->right)
        {
            auto tmp = s;
            reverse(tmp.begin(), tmp.end());
            if(ans == "")
                ans = tmp;
            else
                ans = min(ans, tmp);
        }

        solve(r->left);
        solve(r->right);

        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* r)
    {
        ans = "";
        solve(r);
        return ans;
    }
};

int main()
{
    // skip
}
