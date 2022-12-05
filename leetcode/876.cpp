/*
 * Leetcode Medium 876. Middle of the Linked List
 * author: roy4801
 * AC(C++) 8ms
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
    ListNode* middleNode(ListNode* head)
    {
        int siz = 0;
        ListNode *a = head;
        while(a) siz++, a = a->next;
        
        if(siz % 2 != 0)
            siz = (siz+1)/2;
        else
            siz = siz/2+1;
        
        siz--;
        a = head;
        for(int i = 0; i < siz; i++)
            a = a->next;

        return a;
    }
};
int main()
{
    // skip
}