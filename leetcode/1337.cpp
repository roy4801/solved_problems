/*
 * Leetcode Easy 1337. The K Weakest Rows in a Matrix
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

using P=array<int,2>;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector<int> ans;
        priority_queue<P,vector<P>,greater<P>> pq;
        for(int i = 0; i < mat.size(); i++)
        {
            int s = 0;
            for(int j = 0; j < mat[i].size(); j++)
                if(mat[i][j])
                    s++;
            pq.push({s, i});
        }
        while(k--)
        {
            auto p = pq.top();
            pq.pop();
            ans.push_back(p[1]);
        }
        return ans;
    }
};

/* binary serarch
//          l
//          v
// 1, 1, 1, 0, 0
int l = 0, r = mat[i].size();
while(l < r)
{
    int mid = (l+r)/2;
    if(mat[i][mid] >= 1)
        l = mid+1;
    else
        r = mid;
}
*/

int main()
{
    // skip
}
