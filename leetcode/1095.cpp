/*
 * Leetcode Hard 1095. Find in Mountain Array
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
    int n;
    int findInMountainArray(int t, MountainArray &m)
    {
        n = m.length();

        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l+r)/2;
            int v = mid+1 < n ? m.get(mid+1) : 0;

            if(v > m.get(mid))
                l = mid+1;
            else
                r = mid;
        }

        int maxi = l;

        l = 0, r = maxi+1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(t > m.get(mid))
                l = mid+1;
            else
                r = mid;
        }

        if(m.get(l) == t)
            return l;

        l = maxi+1, r = n-1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(t < m.get(mid))
                l = mid+1;
            else
                r = mid;
        }

        if(m.get(l) == t)
            return l;

        return -1;
    }
};

int main()
{
    // skip
}