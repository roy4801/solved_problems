/*
 * Leetcode Medium 92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        vector<ListNode*> v;

        ListNode *n = head;
        int i = 1;
        bool ok = 0;
        while(n)
        {
            if(i == left)
                ok = 1;

            if(ok)
                v.push_back(n);

            if(i == right)
                break;

            n = n->next;
            i++;
        }
        int siz = v.size();
        for(int i = 0; i < siz/2; i++)
            swap(v[i]->val, v[siz-1-i]->val);
        return head;
    }
};

int main()
{
    // skip
}
