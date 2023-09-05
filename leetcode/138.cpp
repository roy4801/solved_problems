/*
 * Leetcode Medium 138. Copy List with Random Pointer
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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    map<Node*, Node*> M;
    
    Node* copyRandomList(Node* h)
    {
        if(!h) return nullptr;
        // Create new node
        Node *c = h;
        while(c)
        {
            M[c] = new Node(c->val);
            c = c->next;
        }
        // Link next and random
        for(auto &&[o, n] : M)
        {
            n->next = o->next ? M[o->next] : nullptr;
            n->random = o->random ? M[o->random] : nullptr;
        }
        return M[h];
    }
};

class Solution2
{
public:
    Node* copyRandomList(Node* head)
    {
        map<Node*, Node*> rm; // old node random map (from, to)
        Node *n = head;
        while(n)
        {
            rm[n] = n->random;
            n = n->next;
        }
        // copy list
        map<Node*, Node*> otn; // old node to new node
        Node *nh, *prev = nullptr;
        n = head;
        while(n)
        {
            nh = new Node(n->val);
            if(prev)
                prev->next = nh;
            otn[n] = nh;
            prev = nh;
            n = n->next;
        }
        // link random
        n = head;
        while(n)
        {
            otn[n]->random = otn[rm[n]];
            n = n->next;
        }
        return otn[head];
    }
};

int main()
{
    // Skip
}
