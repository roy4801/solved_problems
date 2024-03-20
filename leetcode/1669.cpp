/*
 * Leetcode Medium 1669. Merge In Between Linked Lists
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
    ListNode* mergeInBetween(ListNode* A, int a, int b, ListNode* B)
    {
        ListNode* pA_1, *pA, *pB, *pB_1;
        int i = 0;
        ListNode* n = A, *prev = nullptr;
        while(n->next)
        {
            if(i == a)
            {
                pA = n;
                pA_1 = prev;
            }
            if(i == b)
            {
                pB = n;
                pB_1 = n->next;
            }

            i++;
            prev = n;
            n = n->next;
        }

        ListNode* head = A;

        pA_1->next = B;
        while(B->next)
            B = B->next;
        B->next = pB_1;
        pB->next = nullptr;

        return head;
    }
};

int main()
{
    // skip
}
