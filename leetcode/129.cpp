/*
 * Leetcode Medium 129. Sum Root to Leaf Numbers
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
    int solve(TreeNode* p, int num)
    {
        if(!p) return 0;

        num *= 10;
        num += p->val;

        if(!p->left && !p->right)
        {
            return num;
        }
        else
        {
            return solve(p->left, num) + solve(p->right, num);
        }
    }
    int sumNumbers(TreeNode* r)
    {
        return solve(r, 0);
    }
};

int main()
{
    // skip
}
