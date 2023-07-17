/*
 * Leetcode Medium 445. Add Two Numbers II
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
    ListNode* addZero(ListNode *l, int &siz, int tar)
    {
        while(siz < tar)
        {
            ListNode *cur = new ListNode;
            cur->next = l;
            l = cur;
            siz++;
        }
        return l;
    }
    int count(ListNode *p)
    {
        int num = 0;
        while(p)
            num++, p = p->next;
        return num;
    }
    ListNode* add(ListNode *a, ListNode *b, int n)
    {
        ListNode *res = new ListNode, *head = res;
        ListNode **cur = &res;
        for(int i = 0; i < n; i++)
        {
            auto& p = *cur;
            if(p == nullptr)
                p = new ListNode;
            p->val = a->val + b->val;
            cur = &p->next;
            a = a->next;
            b = b->next;
        }
        carry(nullptr, head, &head);
        return head;
    }
    void carry(ListNode *par, ListNode *l, ListNode **head)
    {
        if(l->next)
            carry(l, l->next, head);

        bool ret = false;
        if(!par)
            ret = true;
        // carry
        if(l->val >= 10)
        {
            if(!par)
            {
                par = new ListNode;
                par->next = l;
            }
            par->val += l->val / 10;
            l->val %= 10;
        }

        if(ret)
            *head = par ? par : l;
    }
    ListNode* addTwoNumbers(ListNode* a, ListNode* b)
    {
        // count num
        int an = 1, bn = 1;
        an = count(a);
        bn = count(b);
        // adding zeros
        if(an > bn)
            b = addZero(b, bn, an);
        else if(an < bn)
            a = addZero(a, an, bn);
        // calc
        return add(a, b, an);
    }
};

int main()
{
    // skip
}
