/*
 * Leetcode Medium 2130. Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head)
    {
        vector<int> v;
        int siz = 0;
        ListNode* n = head;

        while(n)
        {
            siz++;
            n = n->next;
        }

        int hs = siz / 2;
        v.resize(hs, 0);
        int i = 0;
        n = head;
        while(n)
        {
            if(i >= hs)
                v[hs-1-(i-hs)] += n->val;
            else
                v[i] += n->val;
            i++;
            n = n->next;
        }

        int ans = INT_MIN;
        for(int a : v)
            ans = max(ans, a);
        return ans;
    }
};

int main()
{
    // skip
}
