/*
 * Leetcode Medium 1503. Last Moment Before All Ants Fall Out of a Plank
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
    int getLastMoment(int n, vector<int>& left, vector<int>& right)
    {
        int lm = 0, rm = 0;
        for(int i = 0; i < left.size(); i++)
            lm = max(lm, left[i]); // 與最左的距離差
        for(int i = 0; i < right.size(); i++)
            rm = max(rm, n-right[i]); // 與最右的距離差
        return max(lm, rm);
    }
};

int main()
{
    // skip
}