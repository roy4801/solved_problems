/*
 * Leetcode Medium 1396. Design Underground System
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

class UndergroundSystem {
public:
    UndergroundSystem()
    {
        sid.clear();
        id = 0;
        time = {};
    }
    
    void checkIn(int id, string sname, int t)
    {
        p[id] = MP(getId(sname), t);
    }
    
    void checkOut(int id, string sname, int toTime)
    {
        int fr = p[id].X, frTime = p[id].Y;
        int to = getId(sname);

        auto cur = time[MP(fr, to)];
        time[MP(fr, to)] = MP(cur.X + (toTime-frTime), cur.Y+1);
    }
    
    double getAverageTime(string start, string end)
    {
        auto cur = time[MP(getId(start), getId(end))];
        return cur.X / (double)cur.Y;
    }

    unordered_map<string, int> sid;
    int id = 0;
    int getId(string& s)
    {
        if(!sid.count(s))
            sid[s] = id++;
        return sid[s];
    }

    map<P, P> time; // (fr, to) -> (time, people)
    map<int, P> p; // pid -> (from station, time)
};

int main()
{
    // skip
}