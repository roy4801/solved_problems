/*
 * Leetcode Easy 1502. Can Make Arithmetic Progression From Sequence
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
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int dif = arr[1]-arr[0];
        for(int i = 1; i < n-1; i++)
        {
            if(arr[i+1]-arr[i] != dif)
                return false;
        }
        return true;
    }
};

int main()
{
    // skip
}
