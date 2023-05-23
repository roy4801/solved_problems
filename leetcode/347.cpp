/*
 * Leetcode Medium 347. Top K Frequent Elements
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

class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k)
    {
        // sort & create a map for counting numbers
        map<int, int> m;
        sort(v.begin(), v.end());
        for(int i : v)
            m[i]++;
        
        // convert the count map to vecter <count, number> for sorting
        vector<pair<int, int>> vp;
        for(auto &&[num, cnt] : m)
            vp.emplace_back(cnt, num);
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());

        // iterater through the map for top k elements
        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(vp[i].second);
        return ans;
    }
};

int main()
{
    // skip
}
