/*
 * Leetcode Medium 539. Minimum Time Difference
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
    const int DAY = 60*24;
    inline int convert(string& s)
    {
        int h = stol(s.substr(0, 2));
        int m = stol(s.substr(3, 2));
        return 60*h + m;
    }
    inline int dis(string& a, string& b)
    {
        int am = convert(a), bm = convert(b);
        int A = (DAY - am) + bm;
        int B = abs(am - bm);
        return min(A, B);
    }
    int findMinDifference(vector<string>& tp)
    {
        int ans = INT_MAX;
        int n = tp.size();
        sort(tp.begin(), tp.end());
        for(int i = 0; i < n; i++)
        {
            int d = dis(tp[i], tp[(i+1)%n]);
            ans = min(ans, d);
        }
        return ans;
    }
};

int main()
{
    // skip
}