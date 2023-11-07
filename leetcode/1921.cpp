/*
 * Leetcode Medium 1921. Eliminate Maximum Number of Monsters
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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed)
    {
        vector<double> arr; // arrive at time
        int n = dist.size();
        for(int i = 0; i < n; i++)
            arr.push_back(dist[i]/(double)speed[i]);

        sort(arr.begin(), arr.end());

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > i)
                ans++;
            else
                break;
        }

        return ans;
    }
};

int main()
{
    // skip
}
