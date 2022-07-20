/*
 * Leetcode Medium 2221. Check if a Parentheses String Can Be Valid
 * author: roy4801
 * (C++)
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
    int triangularSum(vector<int>& v)
    {
        for(int i = 0; i < v.size()-1; i++)
        {
            for(int j = 0; j < v.size()-1-i; j++)
            {
                v[j] = (v[j] + v[j+1]) % 10;
            }
        }
        return v[0];
    }
};

int main()
{
    // skip
}