/*
 * Leetcode Medium 1146. Snapshot Array
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

#define MP make_pair
using P=pair<int,int>;
class SnapshotArray {
public:
    SnapshotArray(int len)
    {
        s.resize(len);
        for(int i = 0; i < len; i++)
            s[i].emplace_back(0, 0);
    }
    
    void set(int i, int val)
    {
        s[i].emplace_back(id, val);
    }
    
    int snap()
    {
        return id++;
    }
    
    int get(int i, int sid)
    {
        auto it = upper_bound(s[i].begin(), s[i].end(), MP(sid, INT_MAX));
        it--;
        return it->second;
    }

    int get2(int i, int sid)
    {
        int l = 0, r = s[i].size();
        while(l < r)
        {
            int mid = (l+r)/2;
            if(s[i][mid].first <= sid)
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }

        return s[i][l-1].second;
    }

    vector<vector<P>> s; // [idx] -> {(snap1, num1), (snap2, num2), ... }
    int id = 0;
};

int main()
{
    // skip
}