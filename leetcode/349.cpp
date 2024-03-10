/*
 * Leetcode Easy 349. Intersection of Two Arrays
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
    vector<int> intersection(vector<int>& a, vector<int>& b)
    {
        vector<int> ans;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while(i < n && j < m)
        {
            int A = a[i];
            int B = b[j];

            if(A < B)
                i++;
            else if (A > B)
                j++;
            else
            {
                auto it = lower_bound(ans.begin(), ans.end(), A);
                if(it == ans.end())
                    ans.insert(it, A);
                i++;
                j++;
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}