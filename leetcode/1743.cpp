/*
 * Leetcode Medium 1743. Restore the Array From Adjacent Pairs
 * author: roy4801
 * (C++)
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
    map<int, vector<int>> m;
    vector<int> restoreArray(vector<vector<int>>& p)
    {
        int n = p.size();
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            m[p[i][0]].push_back(p[i][1]);
            m[p[i][1]].push_back(p[i][0]);
        }

        for(auto& [i, v] : m)
        {
            if(v.size() == 1)
            {
                ans.push_back(i);
                break;
            }
        }

        int cnt = 0;
        int cur = ans.back(), prev = INT_MIN;
        while(prev != cur)
        {
            for(int i : m[cur]) 
            {
                if(i != prev)
                {
                    ans.push_back(i);
                    prev = cur;
                    cur = i;
                    cnt = 0;
                    break;
                }
                else
                {
                    cnt++;
                    if(cnt >= 2)
                        goto end;
                }
                
            }
        }
    end:
        return ans;
    }
};

/*
Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
*/

int main()
{
    using InputType=vector<vector<int>>;
    vector<InputType> v = {
        {{2,1}, {3,4}, {3,2}},
    };
    for(auto& i : v)
        DBG(Solution{}.restoreArray(i));
}
