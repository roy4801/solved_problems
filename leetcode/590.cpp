/*
 * Leetcode Easy 590. N-ary Tree Postorder Traversal
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

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Recirsive
using P = pair<int,int>;
class Solution {
public:
    vector<int> ans;
    void dfs(Node* r)
    {
        if(!r) return;
        for(auto p : r->children)
        {
            dfs(p);
            ans.push_back(p->val);
        }
    }
    vector<int> postorder(Node* root)
    {
        if(!root) return ans;
        Node* r = new Node(-1, {root});
        ans.clear();
        dfs(r);
        return ans;
    }
};

// Interatively
class Solution {
public:
    vector<int> postorder(Node* root)
    {
        vector<int> ans;
        stack<Node*> s;
        if(root) s.push(root);
        while(!s.empty())
        {
            auto p = s.top(); s.pop();
            ans.push_back(p->val);
            for(auto pp : p->children)
            {
                s.push(pp);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    // skip
}