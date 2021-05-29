/*
 * Leetcode Easy 26. Remove Duplicates from Sorted Array
 * author: roy4801
 * AC(C++) 0.008
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int cnt = 0;
        int l = 0, t = 1;

        if(n.size() == 0) return 0;

        for(int i = 1; i < n.size(); i++)
        {
            if(n[l] != n[i])
            {
                l = i;
                n[t++] = n[i];
            }
        }
        return t;
    }
};

int main()
{
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    printf("%d\n", (Solution{}).removeDuplicates(v));
    print(v);
}