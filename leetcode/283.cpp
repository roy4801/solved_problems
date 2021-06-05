/*
 * Leetcode Easy 283. Move Zeroes
 * author: roy4801
 * AC(C++) 0.012
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
	void moveZeroes(vector<int>& n) {
        int t = 0; // target
        for(int i = 0; i < n.size(); i++)
        {
        	if(n[i] != 0)
        		n[t++] = n[i];
        }
        for(int i = t; i < n.size(); i++)
        	n[i] = 0;
    }
};

int main()
{
	vector<int> v = {0,1,0,3,12,0};
	Solution{}.moveZeroes(v);
	DBG(v);
}