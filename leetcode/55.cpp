/*
 * Leetcode Medium 55. Jump Game
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
    bool canJump(vector<int>& N)
    {
        int b = N.size()-1, a = b-1;
        while(a >= 0)
        {
            if(a + N[a] >= b)
            {
                b = a;
            }
            a--;
        }
        return b == 0;
    }
};

int main()
{
    // skip
}