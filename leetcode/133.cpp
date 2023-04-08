/*
 * Leetcode Medium 133. Clone Graph
 * author: roy4801
 * AC(C++) 12ms 8.5MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution {
public:
    map<Node*, bool> vis;
    map<Node*, Node*> o2n; // old to new
    Node* bfs(Node *n)
    {
        if(!n) return nullptr;
        o2n[n] = new Node(n->val);

        queue<Node*> q;
        q.push(n);
        vis[n] = true;
        
        while(!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            
            o2n[cur]->val = cur->val;
            
            for(Node *a : cur->neighbors)
            {
                if(!o2n.count(a))
                    o2n[a] = new Node(a->val);
                
                o2n[cur]->neighbors.push_back(o2n[a]);
                
                if(!vis.count(a))
                {
                    q.push(a);
                    vis[a] = true;
                }
            }
        }
        
        return o2n[n];
    }
    
    Node* cloneGraph(Node* node)
    {
        return bfs(node);
    }
};

class Solution2 {
public:
    unordered_map<Node*, Node*> m; // old -> new
    unordered_map<Node*, bool> visit;

    inline Node* GetNode(Node *n)
    {
        if(!m.count(n))
        {
            m[n] = new Node();
        }
        return m[n];
    }

    Node* cloneGraph(Node* n)
    {
        if(!n)
            return nullptr;

        Node *ans;
        queue<Node*> q;

        q.push(n);
        visit[n] = true;

        while(!q.empty())
        {
            Node *cur = q.front(); q.pop();
            GetNode(cur)->val = cur->val;

            for(Node *i : cur->neighbors)
            {
                GetNode(i)->val = i->val;
                GetNode(cur)->neighbors.push_back(GetNode(i));
                
                if(!visit[i])
                {
                    visit[i] = true;
                    q.push(i);
                }
            }
        }

        return GetNode(n);
    }
};

// dfs
class Solution3 {
public:
    unordered_map<Node*, Node*> m; // old -> new
    unordered_map<Node*, bool> visit;

    inline Node* GetNode(Node *n)
    {
        if(!m.count(n))
        {
            m[n] = new Node();
        }
        return m[n];
    }

    Node* cloneGraph(Node* n)
    {
        if(!n) return nullptr;
        if(m.count(n)) return m[n];

        Node *nn = GetNode(n);
        nn->val = n->val;
        for(auto i : n->neighbors)
        {
            auto ii = cloneGraph(i);
            nn->neighbors.push_back(ii);
        }
        return nn;
    }
};

int main()
{
    // im too lazy ...
}