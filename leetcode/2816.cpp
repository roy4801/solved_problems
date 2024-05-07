/*
 * Leetcode Medium 2816. Double a Number Represented as a Linked List
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
    ListNode* doubleIt(ListNode* head)
    {
        vector<int> v;
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());

        int n = v.size();
        for(int i = 0; i < n; i++)
            v[i] *= 2;

        for(int i = 0; i < n; i++)
        {
            if(v[i] >= 10)
            {
                if(i+1 < n)
                    v[i+1] += v[i] / 10;
                else
                    v.push_back(v[i] / 10);
                v[i] %= 10;
            }
        }

        ListNode* ans;
        ListNode** p = &ans;
        for(int i = v.size()-1; i >= 0; i--)
        {
            *p = new ListNode(v[i]);
            p = &(*p)->next;
        }
        return ans;
    }
};

class Solution2 {
public:
    ListNode* doubleIt(ListNode* head)
    {
        ListNode* p = head;
        if(p->val*2 / 10)
        {
            head = new ListNode(p->val*2 / 10, p);
        }
        while(p)
        {
            p->val = (p->val*2)%10 + (p->next ? (p->next->val*2)/10 : 0);
            p = p->next;
        }
        return head;
    }
};
/*
i = (i*2)%10 + (i+1)*2/10
*/

int main()
{
    // skip
}