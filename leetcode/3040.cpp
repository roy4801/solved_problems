/*
 * Leetcode Medium 3040. Maximum Number of Operations With the Same Score II
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

#define N 2000
class Solution {
public:
    int* v;
    int ans = INT_MIN;
    int memo[N+5][N+5];
    int solve(int a, int b, int num)
    {
        if(a >= b)
            return 0;
        if(memo[a][b] != -1)
            return memo[a][b];
        
        int A = 0, B = 0, C = 0;
        if((num != -1 && v[a]+v[a+1] == num) || num == -1)
        {
            A = solve(a+2, b, v[a]+v[a+1])+1;
        }
        if((num != -1 && v[b-1]+v[b] == num) || num == -1)
        {
            B = solve(a, b-2, v[b-1]+v[b])+1;
        }
        if((num != -1 && v[a]+v[b] == num) || num == -1)
        {
            C = solve(a+1, b-1, v[a]+v[b])+1;
        }

        return memo[a][b] = max({A, B, C});
    }
    
    int maxOperations(vector<int>& nums)
    {
        int n = nums.size();
        v = &nums[0];
        memset(memo, 0xff, sizeof(memo));
        return solve(0, n-1, -1);
    }
};

/*
0 = Choose the first two elements of nums and delete them.
1 = Choose the last two elements of nums and delete them.
2 = Choose the first and the last elements of nums and delete them.
*/

int main()
{
    // skip
}