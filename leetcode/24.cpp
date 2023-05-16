/*
 * Leetcode Medium 24. Swap Nodes in Pairs
 * author: roy4801
 * AC(C++) 4ms 7.5MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode *newHead = head, *prev = nullptr;
        bool changed = false;
        while(head)
        {
            if(!head->next) break;

            ListNode *a = head, *b = head->next;
            ListNode *tmp = head->next->next;
            
            if(prev) prev->next = b;
            b->next = a;
            a->next = tmp;
            
            if(!changed) newHead = b;
            changed = true;
            
            prev = a;
            head = tmp;
        }
        return newHead;
    }
};

class Solution2
{
public:
    ListNode* swapPairs(ListNode* h)
    {
        ListNode *a = nullptr, *b = nullptr, *c, *n = h;

        int i = 0;
        while(n)
        {
            i++;
            c = n;
            n = n->next;
            
            if(i % 2 == 0)
            {
                if(a)
                {
                    // 1 2 3 4
                    //   a b c n
                    //   a c b n
                    a->next = c;
                    c->next = b;
                    b->next = n;
                }
                else
                {
                    // 1 2 3 4
                    // b c n
                    // c b n
                    b->next = n;
                    c->next = b;
                    h = c;
                }
                a = c;
            }
            else
            {
                a = b;
                b = c;
            }
        }
        return h;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    auto res = Solution{}.swapPairs(build_sll(v));
    DBG(res);
}