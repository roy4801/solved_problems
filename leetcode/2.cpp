/*
 * Leetcode Medium 2. Add Two Numbers
 * author: roy4801
 * AC(C++) 0.024
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create(int num)
{
    ListNode *n = new ListNode, *h = n;
    while(num)
    {
        if (num >= 10)
        {
            n->next = new ListNode;
        }
        n->val = num % 10;
        num /= 10;
        if(n->next)
            n = n->next;
    }
    return h;
}

void print(ListNode *h)
{
    while(h)
    {
        printf("%d", h->val);
        h = h->next;
    }
}

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *a, ListNode *b)
    {
        ListNode *n = new ListNode;
        ListNode *h = n;

        while (a || b)
        {
            printf("%d", n->val);
            if (a)
            {
                printf("+%d", a->val);
                n->val += a->val;
                a = a->next;
            }

            if (b)
            {
                printf("+%d", b->val);
                n->val += b->val;
                b = b->next;
            }

            printf("=%d\n", n->val);

            if (n->val >= 10)
            {
                n->next = new ListNode(n->val / 10);
                n->val %= 10;
                n = n->next;
            }
            else if(a || b)
            {
                n->next = new ListNode;
                n = n->next;
            }
        }

        return h;
    }
};

int main()
{
    print(Solution{}.addTwoNumbers(create(243), create(564)));
}