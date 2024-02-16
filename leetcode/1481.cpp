/*
 * Leetcode Medium 1481. Least Number of Unique Integers after K Removals
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

using P = pair<int,int>;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        int n = arr.size();

        map<int, int> m;
        for(int i : arr)
            m[i]++;

        priority_queue<P, vector<P>, greater<>> pq;
        for(auto [num, cnt] : m)
            pq.push({cnt, num});

        for(int i = 0; i < k; i++)
        {
            auto [cnt, num] = pq.top();
            pq.pop();
            cnt--;
            if(cnt > 0)
                pq.push({cnt, num});
        }

        return pq.size();
    }
};

int main()
{
    // skip
}
