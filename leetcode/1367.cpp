/*
 * Leetcode Medium 1367. Linked List in Binary Tree
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
    set<string> p;
    void dfs(TreeNode* r, string& path)
    {
        if(!r)
            return;
        
        const auto s = to_string(r->val);

        path += s;
        if(!r->left && !r->right)
            p.insert(path);

        dfs(r->left, path);
        dfs(r->right, path);

        for(int i = 0; i < s.size(); i++)
            path.pop_back();
    }
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        p.clear();

        string path;
        dfs(root, path);
        path.clear();
        
        while(head)
        {
            path += to_string(head->val);
            head = head->next;
        }

        for(auto& pp : p)
        {
            if(pp.find(path) != string::npos)
            {
                return 1;
            }
        }

        return 0;
    }
};

class Solution {
public:
    bool dfs(ListNode* head,TreeNode* r)
    {
        if(!head)
            return 1;
        if(!r)
            return 0;
        if(head->val != r->val)
            return 0;
        return dfs(head->next, r->left) || dfs(head->next, r->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if(!root)
            return 0;
        if(dfs(head, root))
            return 1;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

int main()
{
    // skip
}