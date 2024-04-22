/*
 * Leetcode Medium 752. Open the Lock
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
    vector<vector<int>> G;
    unordered_map<string, int> s2id;
    int gid = 0;
    inline int getId(const string& s)
    {
        if(!s2id.count(s))
        {
            s2id[s] = gid++;
            G.resize(gid);
        }
        return s2id[s];
    }
    set<int> dead;

    inline string to_str(int a, int b, int c, int d)
    {
        if(a < 0) a += 10;
        if(a > 9) a -= 10;
        if(b < 0) b += 10;
        if(b > 9) b -= 10;
        if(c < 0) c += 10;
        if(c > 9) c -= 10;
        if(d < 0) d += 10;
        if(d > 9) d -= 10;
        return to_string(a)+to_string(b)+to_string(c)+to_string(d);
    }

    void connect(string& a, string& b)
    {
        int A = getId(a);
        int B = getId(b);
        if(dead.count(A) || dead.count(B))
            return;
        G[A].push_back(B);
        G[B].push_back(A); 
    }
    void build()
    {
        for(int a = 0; a <= 9; a++)
        for(int b = 0; b <= 9; b++)
        for(int c = 0; c <= 9; c++)
        for(int d = 0; d <= 9; d++)
        {
            string fr, to;
            fr = to_str(a, b, c, d);
            to = to_str(a-1, b, c, d);
            connect(fr, to);
            to = to_str(a+1, b, c, d);
            connect(fr, to);
            to = to_str(a, b-1, c, d);
            connect(fr, to);
            to = to_str(a, b+1, c, d);
            connect(fr, to);
            to = to_str(a, b, c-1, d);
            connect(fr, to);
            to = to_str(a, b, c+1, d);
            connect(fr, to);
            to = to_str(a, b, c, d-1);
            connect(fr, to);
            to = to_str(a, b, c, d+1);
            connect(fr, to);
        }
    }

    const int inf = 100000;
    int openLock(vector<string>& deadends, string target)
    {
        for(auto& i : deadends)
            dead.insert(getId(i));
        build();

        int src = getId("0000"), dst = getId(target);
        using P=pair<int,int>; // w, idx
        vector<int> d(G.size(), inf);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.emplace(0, src);
        while(!pq.empty())
        {
            auto [w, i] = pq.top();
            pq.pop();

            if(d[i] != inf)
                continue;

            d[i] = w;
            for(int j : G[i])
            {
                if(d[j] == inf)
                    pq.emplace(w+1, j);
            }
        }
        return d[dst] == inf ? -1 : d[dst] ;
    }
};

int main()
{
    // skip
}