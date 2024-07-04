/*
 * Leetcode Medium 2181. Merge Nodes in Between Zeros
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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* ans;
        ListNode** cur = &ans;

        int sum = 0;
        int i = 0;
        while(head)
        {
            if(head->val == 0)
            {
                if(i)
                {
                    *cur = new ListNode(sum);
                    cur = &(*cur)->next;
                }
                sum = 0;
                i++;
            }
            else
            {
                sum += head->val;
            }
            head = head->next;
        }
        return ans;
    }
};

int main()
{
    // skip
}