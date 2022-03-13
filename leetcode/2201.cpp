/*
 * Leetcode Medium 2201. Count Artifacts That Can Be Extracted
 * author: roy4801
 * (C++)
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

using P=pair<int,int>;
#define MP make_pair

class Solution {
public:
    map<P, int> map2art;
    map<int, int> an;
    
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig)
    {
        for(int k = 0; k < art.size(); k++)
        {
            for(int i = art[k][0]; i <= art[k][2]; i++)
                for(int j = art[k][1]; j <= art[k][3]; j++)
                {
                    map2art[MP(i, j)] = k;
                    an[k]++;
                }
        }
        
        for(int i = 0; i < dig.size(); i++)
        {
            auto tmp = MP(dig[i][0], dig[i][1]);
            if(map2art.count(tmp))
            {
                an[map2art[tmp]]--;
            }
        }
               
        int ans = 0;
        for(auto && [k, v] : an)
        {
            if(v == 0)
                ans++;
        }
        return ans;
    }
};

int main()
{
    // skip
}