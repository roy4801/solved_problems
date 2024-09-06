/*
 * Leetcode Medium 3217. Delete Nodes From Linked List Present in Array
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    { 
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode *h, **p = &h;

        while(head)
        {
            if(!s.count(head->val))
            {
                *p = head;
                p = &(*p)->next;
            }
            auto prev = head;
            head = head->next;
            prev->next = nullptr;
        }
        return h;
    }
};

int main()
{
    // skip
}