/*
 * Leetcode Easy 141. Linked List Cycle
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    set<ListNode*> s;
    bool intuition(ListNode *head)
    {
        ListNode *cur = head;
        while(cur)
        {
            if(s.count(cur))
            {
                return true;
            }
            s.insert(cur);
            cur = cur->next;
        }
        return false;
    }

    bool floyd(ListNode *head)
    {
        ListNode *a = head, *b = head;
        while(b && b->next)
        {
            a = a->next;
            b = b->next->next;
            
            if(a == b)
                return true;
        }
        return false;
    }

    bool hasCycle(ListNode *head)
    {
        return floyd(head);
    }
};

class Solution2
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *a = head, *b = head;
        if(head && head->next == nullptr)
            return 0;
        while(a && b)
        {
            if(a)
                a = a->next;
            if(b)
                b = b->next;
            if(b)
                b = b->next;
            if(a == b)
                return 1;
        }
        return 0;
    }
};

int main()
{
    // vector<int> v = {3,2,0,-4};
    // int pos = 1;
    vector<int> v = {1,2};
    int pos = 0;
    // vector<int> v = {1};
    // int pos = -1;
    //
    ListNode *h = build_sll(v), *last = h, *c = h;
    while(last->next)
        last = last->next;
    while(pos > 0 && c->next)
    {
        c = c->next;
        pos--;
    }
    //
    cout << Solution{}.hasCycle(h) << '\n';
}
