/*
 * Leetcode Easy 941. Sort Array By Parity
 * author: roy4801
 * OK(C++) 0.208
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    bool validMountainArray(vector<int>& n) {
        bool up = true;
        int a = 0, b = 0;
        for(int i = 0; i < n.size()-1; i++)
        {
            printf(">> %d\n", n[i]);
            if(up)
            {
                if(n[i] < n[i+1])
                    a++;
                else
                    up = false;
            }
            if(!up)
            {
                if(n[i] > n[i+1])
                    b++;
            }
            printf("a = %d, b = %d\n", a, b);
        }
        return a > 0 && b > 0 && a+b == n.size()-1;
    }
};

int main()
{
    vector<int> v = {2,1};
    DBG(Solution{}.validMountainArray(v));
}