/*
 * Leetcode Easy 217. Contains Duplicate
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
    bool containsDuplicate(vector<int>& n)
    {
        sort(n.begin(), n.end());
        for(int i = 0; i < n.size()-1; i++)
        {
            if(n[i] == n[i+1])
                return true;
        }
        return false;
    }
};

int main()
{
    // skip
}