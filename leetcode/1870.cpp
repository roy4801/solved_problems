/*
 * Leetcode Medium 1870. Minimum Speed to Arrive on Time
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
    int minSpeedOnTime(vector<int>& dist, double h)
    {
        int n = dist.size();
        auto ok = [&](int speed) -> double
        {
            double t = 0;
            for(int i = 0; i < n; i++)
            {
                if(i != n-1)
                    t += ceil(dist[i] / (double)speed);
                else
                    t += dist[i] / (double)speed;
            }
            return t;
        };

        int l = 1, r = 1e7+1; // speed
        while(l < r)
        {
            int mid = (l+r)/2;
            double t = ok(mid);
            if(t > h) // time
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        return l != (int)1e7+1 ? l : -1;
    }
};

int main()
{
    // skip
}
