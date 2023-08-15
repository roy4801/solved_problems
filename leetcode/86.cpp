/*
 * Leetcode Medium 86. Partition List
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

using P=pair<ListNode*,ListNode*>;
#define X first
#define Y second
class Solution {
public:
    ListNode* partition(ListNode* h, int x)
    {
        ListNode *cur = h, *prev = nullptr;
        P l, g; // <start, end>
        bool ok = 0;

        auto add = [&](P &p, ListNode* n)
        {
            if(p.X)
                p.Y->next = n;
            else
                p.X = n;
            p.Y = n;
        };

        while(cur)
        {
            ListNode *next = cur->next;

            cur->next = nullptr;
            if(cur->val < x)
                add(l, cur);
            else
                add(g, cur);

            cur = next;
            ok = 1;
        }

        if(!ok)
            return 0;

        if(l.Y)
        {
            l.Y->next = g.X;
            return l.X;
        }
        else
            return g.X;
    }
};

int main()
{
    // skip
}