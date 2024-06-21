/*
 * Leetcode Medium 1052. Grumpy Bookstore Owner
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
    int maxSatisfied(vector<int>& c, vector<int>& g, int min)
    {
        int n = c.size();
        int sum = 0;

        // 統計 0 數量
        for(int i = 0; i < n; i++)
            if(g[i] == 0)
                sum += c[i];
        
        // 使用 min 將 [0, min-1] 都變成 0，統計 1->0 的總和
        int i = 0, j = min-1;
        for(int a = 0; a < min; a++)
            if(g[a] == 1)
                sum += c[a];

        // 雙指標，每次往前 i 要扣掉，j 要加入，要判斷 1 (因為 1->0)
        int ans = sum;
        while(j < n)
        {
            if(g[i] == 1)
                sum -= c[i];
            if(j+1 < n && g[j+1] == 1)
                sum += c[j+1];
            ans = max(ans, sum);
            i++;
            j++;
        }
        return ans;
    }
};

int main()
{
    // skip
}