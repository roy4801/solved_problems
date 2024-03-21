/*
 * Leetcode Easy 206. Reverse Linked List
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode *p = nullptr, *prev = nullptr;

        while(head)
        {
            p = new ListNode(head->val);
            if(prev)
                p->next = prev;

            prev = p;
            head = head->next;
        }

        return p;
    }
};

int main()
{
    // skip
}
