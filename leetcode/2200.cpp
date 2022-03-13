/*
 * Leetcode Easy 2200. Find All K-Distant Indices in an Array
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
    bool ok[1005];
    vector<int> findKDistantIndices(vector<int>& n, int key, int k)
    {
        vector<int> a, ans;
        for(int i = 0; i < n.size(); i++)
            if(n[i] == key)
                a.push_back(i);   
        
        for(int i : a)
        {
            for(int j = i-k; j <= i+k; j++)
                if(j >= 0 && j <= n.size()-1)
                    ok[j] = true;
        }
        for(int i = 0; i <= 1000; i++)
            if(ok[i]) ans.push_back(i);
        return ans;
    }
};

int main()
{
    // skip
}