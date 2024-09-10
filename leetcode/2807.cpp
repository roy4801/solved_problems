/*
 * Leetcode Medium 2807. Insert Greatest Common Divisors in Linked List
 * author: roy4801
 * (C++)
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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* a = head, *b = head->next;
        if(!b) return a;

        while(b)
        {
            a->next = new ListNode(__gcd(a->val, b->val));
            a->next->next = b;

            auto tmp = b->next;
            a = b;
            b = tmp;
        }
        return head;
    }
};

class Solution2 {
public:
    constexpr int gcd(int a, int b)
    {
        a %= b;
        if(a == 0)
            return b;
        else 
            return gcd(b, a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* a = head, *b = head->next;
        if(!b) return a;

        while(b)
        {
            a->next = new ListNode(gcd(max(a->val, b->val), min(a->val, b->val)));
            a->next->next = b;

            auto tmp = b->next;
            a = b;
            b = tmp;
        }
        return head;
    }
};

int main()
{
    // skip
}