/*
 * Leetcode Medium 905. Length of Longest Fibonacci Subsequence
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& n) {
        sort(n.begin(), n.end(), [](int a, int b) {
        	return a % 2 == 0 && b % 2 != 0;
        });
        return n;
    }

    // TODO: Learning more elegant solution
};

int main()
{
	vector<int> v = {3,1,2,4};
	DBG(Solution{}.sortArrayByParity(v));
}