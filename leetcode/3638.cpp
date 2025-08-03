/*
 * Leetcode Medium 3638. Maximum Balanced Shipments
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
    // 題目沒有要求所有的貨物都要被運走 只要能夠運走的貨物數量最大即可
    // 只要有一個貨物的重量小於前面所有貨物的最大重量 就可以運走；如果試到結尾都無法運走 就結束
    int maxBalancedShipments(vector<int>& weight)
    {
        int n = weight.size();
        int ans = 0;
        int i = 0;
        while(i < n)
        {
            bool ok = 0;
            int maxn = weight[i];
            for(int j = i; j < n; j++)
            {
                maxn = max(maxn, weight[j]);
                if(weight[j] < maxn)
                {
                    ans++;
                    i = j+1;
                    ok = 1;
                    break;
                }
            }
            if(!ok)
                break;
        }

        return ans;
    }
};

int main()
{
    // skip
}