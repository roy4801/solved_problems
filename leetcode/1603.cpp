/*
 * Leetcode Easy 1603. Running Sum of 1d Array
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

class ParkingSystem {
public:
    int s[4] = {0};

    ParkingSystem(int a, int b, int c)
    {
        s[1] = a;
        s[2] = b;
        s[3] = c;
    }

    bool addCar(int t)
    {
        if(s[t])
        {
            s[t]--;
            return true;
        }
        return false;
    }
};

int main()
{
    // skip
}
