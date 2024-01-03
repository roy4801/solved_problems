/*
 * Leetcode Medium 2125. Number of Laser Beams in a Bank
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
    int numberOfBeams(vector<string>& bank)
    {
        int n = bank.size(), m = bank[0].size();
        int ans = 0;
        int last = -1;

        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < m; j++)
            {
                if(bank[i][j] == '1')
                    cnt++;
            }

            if(cnt)
            {
                if(last != -1)
                {
                    ans += last * cnt;
                }
                last = cnt;
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
