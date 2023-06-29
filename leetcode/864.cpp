/*
 * Leetcode Hard 864. Shortest Path to Get All Keys
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

#define N 30
#define MP make_tuple

using V=array<bool,7>; // keys
using P=tuple<int,int,int,V>; // i, j, depth, keys
class Solution {
public:
    const int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int shortestPathAllKeys(vector<string>& M)
    {
        int n = M.size(), m = M[0].size();
        int k = 0;
        queue<P> q;
        set<tuple<int,int,V>> vis; // i, j, keys
        auto okgo = [&](int i, int j, V& keys) {
            if( (0 <= i && i < n) && (0 <= j && j < m) )
            {
                char c = M[i][j];
                if(islower(c))
                    return true;
                else if(isupper(c))
                    return keys[tolower(c)-'a'];
                else
                    return c != '#';
            }
            return false;
        };
        auto isFinal = [&](V& keys) {
            for(int i = 0; i < k; i++)
                if(!keys[i])
                    return false;
            return true;
        };

        // find start point & num of keys
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(M[i][j] == '@')
                {
                    q.push({i, j, 0, {}});
                    vis.insert({i, j, {}});
                }
                else if(islower(M[i][j]))
                    k++;

        // bfs
        while(!q.empty())
        {
            auto [i, j, dep, keys] = q.front();
            q.pop();

            // is key?
            if(islower(M[i][j]))
                keys[M[i][j]-'a'] = 1;
            // found all keys?
            if(isFinal(keys))
                return dep;    

            for(int d = 0; d < 4; d++)
            {
                int ni = i+dir[d][0], nj = j+dir[d][1];

                auto x = MP(ni, nj, keys);
                if(okgo(ni, nj, keys) && !vis.count(x))
                {
                    q.push({ni, nj, dep+1, keys});
                    vis.insert(x);
                }
            }
        }

        return -1;
    }
};

int main()
{
    // skip
}