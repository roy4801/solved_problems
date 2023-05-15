/*
 * Leetcode Medium 1721. Swapping Nodes in a Linked List
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

class Solution {
public:
    ListNode* swapNodes(ListNode* h, int k)
    {
        int siz = 0;
        auto n = h;
        while(n)
        {
            siz++;
            n = n->next;
        }
        
        int b = siz-1 - (k-1);
        int a = k-1;
        ListNode* p[2];
        int i = 0;
        n = h;
        while(n)
        {
            if(i == a)
            {
                p[0] = n;
            }
            if(i == b)
            {
                p[1] = n;
            }
            i++;
            n = n->next;
        }

        swap(p[0]->val, p[1]->val);
        return h;
    }
};

int main()
{
    // skip
}