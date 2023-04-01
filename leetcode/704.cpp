/*
 * Leetcode Easy 704. Binary Search
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
    vector<int> n;
    int t;

    int bs_recursive(int l, int r)
    {
        int mid = (l+r)/2;

        if(l == r && r == mid)
            return n[mid] == t ? mid : -1;

        if(n[mid] > t)
            return bs_recursive(l, mid);
        else if(n[mid] < t)
            return bs_recursive(mid+1, r);
        else
            return mid;
    }

    int bs_iterative(int l, int r)
    {
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(n[mid] == t)
                return mid;
            // left
            if(n[mid] > t)
                r = mid-1;
            // right
            else if(n[mid] < t)
                l = mid+1;
        }
        return -1;
    }

    int search(vector<int>& v, int a)
    {
        int l = 0, r = v.size();

        while(l < r)
        {
            int mid = (l+r)/2;
            if(v[mid] >= a)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l < v.size() && v[l]==a ? l : -1;
    }
    
    int search(vector<int>& nums, int target)
    {
        n = nums;
        t = target;
        return bs_iterative(0, n.size()-1);
    }
};

int main()
{
    // vector<int> v = {2, 5};
    // int t = 5;
    // even
    // vector<int> v = {-1,0,3,5,9,12};
    // int t = 9;
    vector<int> v = {-1,0,3,5,9,12};
    int t = 2;
    // odd
    // vector<int> v = {-1,0,5,9,12};
    // int t = 9;
    // vector<int> v = {-1,0,5,9,12};
    // int t = 2;

    cout << Solution{}.search(v, t) << '\n';
}