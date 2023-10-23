/*
 * Leetcode Easy 342. Power of Four
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
    bool isPowerOfFour(int n)
    {
        if(n == 0)
            return 0;
        double tmp = log(n)/log(4);
        return n > 0 && tmp - (int)tmp <= 0.001;
    }
};

/*
16
5
1
-2147483648
2147483647
0
*/

int main()
{
    // skip
}
