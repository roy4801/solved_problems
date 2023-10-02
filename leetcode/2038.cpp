/*
 * Leetcode Medium 2038. Remove Colored Pieces if Both Neighbors are the Same Color
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
    bool winnerOfGame(string colors)
    {
        int n = colors.size();
        vector<bool> a(n), b(n);

        for(int i = 0; i < n; i++)
        {
            if(i < 1 || i > n-2)
                continue;
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1])
            {
                if(colors[i] == 'A')
                {
                    a[i] = 1;
                }
                else // B
                {
                    b[i] = 1;
                }
            }
        }

        int an = 0, bn = 0;
        for(int i = 0; i < n; i++)
            an += a[i];
        for(int i = 0; i < n; i++)
            bn += b[i];
        return an > bn;
    }
};

int main()
{
    // skip
}
