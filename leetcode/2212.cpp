/*
 * Leetcode Medium 2212. Maximum Points in an Archery Competition
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

// backtracking
class Solution
{
public:
    vector<int> A, B;
    int maxB = INT_MIN;

    void solve(int i, int arrow, int score, vector<int> b)
    {
        if(i == -1 || arrow <= 0)
        {
            if(score > maxB)
            {
                // printf("%d %d %d\n", i, arrow, score);
                // 不知道為啥射光所有箭
                if(arrow > 0)
                    b[0] += arrow;

                maxB = score;
                B = b;
            }
            return;
        }
        int shot = A[i]+1;
        // If total arrow is greater than current arrows
        if(arrow >= shot)
        {
            b[i] = shot;
            solve(i-1, arrow-shot, score+i, b);
            b[i] = 0;
        }
        solve(i-1, arrow, score, b);
    }
    
    vector<int> maximumBobPoints(int n, vector<int>& a)
    {
        A = a;
        vector<int> b(12, 0);
        solve(11, n, 0, b);

        return B;
    }
};

/*
9
[1,1,0,1,0,0,2,1,0,1,2,0].
89
[3,2,28,1,7,1,16,7,3,13,3,5]
*/

int main()
{
    // int n = 9;
    // vector<int> a = {1,1,0,1,0,0,2,1,0,1,2,0};
    int n = 89;
    vector<int> a = {3,2,28,1,7,1,16,7,3,13,3,5};
    auto x = Solution{}.maximumBobPoints(n, a);
    DBG(x);
}