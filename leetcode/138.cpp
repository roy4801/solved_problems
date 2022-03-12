/*
 * Leetcode Medium 138. Copy List with Random Pointer
 * author: roy4801
 * (C++)
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

int main()
{
    // Skip
}