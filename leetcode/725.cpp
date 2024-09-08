/*
 * Leetcode Medium 725. Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int n = 0;
        vector<int> sp;

        ListNode* p = head;
        while(p)
        {
            n++;
            p = p->next;
        }

        int div = n / k, mod = n % k;
        sp.resize(k, div);
        for(int i = 0; i < mod; i++)
            sp[i]++;

        vector<ListNode*> ans(k);
        int i = 0, cnt = 0;
        p = head;
        while(p)
        {
            cnt++;
            if(cnt == sp[i])
            {
                ans[i++] = head;
                head = p->next;
                p->next = nullptr;
                p = head;
                cnt = 0;
            }
            else
            {
                p = p->next;
            }
        }
    
        return ans;
    }
};

int main()
{
    // skip
}