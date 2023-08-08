/*
 * Leetcode Medium 33. Search in Rotated Sorted Array
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
    int search(vector<int>& v, int target)
    {
        int n = v.size();
        int off;
        // find the offset
        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(v[mid] <= v[n-1])
                r = mid;
            else
                l = mid + 1;
        }
        off = l;
        // find the target (index by offset)
        l = 0, r = n;
        while(l < r)
        {
            int mid = (l+r)/2, m = (mid+off)%n;
            if(v[m] == target)
                return m;
            else if(v[m] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return -1;
    }
};

int main()
{
    // skip
}