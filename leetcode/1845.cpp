/*
 * Leetcode Medium 1845. Seat Reservation Manager
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

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<>> pq;

    SeatManager(int n)
    {
        for(int i = 1; i <= n; i++)
            pq.push(i);
    }
    
    int reserve()
    {
        int ret = pq.top();
        pq.pop();
        return ret;
    }
    
    void unreserve(int seat)
    {
        pq.push(seat);
    }
};

int main()
{
    // skip
}