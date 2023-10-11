/*
 * Leetcode Hard 2251. Number of Flowers in Full Bloom
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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people)
    {
        int n = flowers.size(), m = people.size();
        vector<int> start, end;
        for(int i = 0; i < n; i++)
        {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> ans;
        for(int i = 0; i < m; i++)
        {
            int v = people[i];
            int a = upper_bound(start.begin(), start.end(), v)-start.begin();
            int b = lower_bound(end.begin(), end.end(), v)-end.begin();
            ans.push_back(a-b);
        }

        return ans;
    }
};

/*
v = 3
    v
1 3 4 9     => 2
6 7 12 13   => 0
^
*/

int main()
{
    // skip
}