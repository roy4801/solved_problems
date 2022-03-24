/*
 * Leetcode Medium 881. Boats to Save People
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

class Solution
{
public:
    int numRescueBoats(vector<int>& n, int l)
    {
        int ans = 0;
        int a = 0, b = n.size()-1;
        
        sort(n.begin(), n.end());
        while(a <= b)
        {
            if(n[a] + n[b] <= l)
                a++;
            b--;
            ans++;
        }
        
        return ans;
    }
};

int main()
{
    // skip
}