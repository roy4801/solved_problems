/*
 * Leetcode Medium 744. Find Smallest Letter Greater Than Target
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
    char nextGreatestLetter(vector<char>& v, char t)
    {
        auto it = upper_bound(v.begin(), v.end(), t);
        return it != v.end() ? *it : v[0];    
    }
};

class Solution2 {
public:
    char nextGreatestLetter(vector<char>& v, char t)
    {
        int l = 0, r = v.size();
        while(l < r)
        {
            int mid = (l+r)/2;

            //       ... mid ... t ... 
            //from: ^l                 ^r
            //to:                  ^l  ^r
            if(v[mid] <= t)
            {
                l = mid+1;
            }
            // v[mid] > t
            //       ... t ... mid  ... 
            //from: ^l                 ^r
            //to:   ^l         ^r        
            else
            {
                r = mid;
            }
        }

        return l < v.size() ? v[l] : v[0];
    }
};

int main()
{
    // skip
}