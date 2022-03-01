/*
 * Leetcode Easy 338. Counting Bits
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define PB push_back

#define N 100000

class Solution {
public:
    // O(NlogN)
    vector<int> intuition(int n)
    {
        vector<int> ans;
        for(int i = 0; i <= n; i++)
        {
            int tmp = i, cnt = 0;
            while(tmp)
            {
                if(tmp & 1)
                    cnt++;
                tmp >>= 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    
    // O(N) 7ms
    vector<int> builtin(int n)
    {
        vector<int> ans;
        for(int i = 0; i <= n; i++)
        {
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
    
    // Top-Down O(N)???
    int table[N+5] = {0};
    int popcnt(int n)
    {
        if(n == 0) return 0;
        else if(n == 1) return 1;
        if(table[n]) return table[n];
        
        int tmp = popcnt(n / 2);
        // if(n % 2 != 0)
        if(n & 1)
            return table[n] = (tmp + 1);
        else
            return table[n] = tmp;
    }
    
    // Bottom-up O(N)
    int build(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            table[i] = table[i/2] + (i&1);
        }
        return table[n];
    }
    
    vector<int> countBits(int n)
    {
        vector<int> ans;
        
        // build(n);
        
        for(int i = 0; i <= n; i++)
        {
            ans.push_back(popcnt(i));
        }
        return ans;
    }
};

int main()
{
    Solution{}.countBits(100000);
}