/*
 * Leetcode Easy 1346. Check If N and Its Double Exist
 * author: roy4801
 * AC(C++) 0.008
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    bool checkIfExist(vector<int>& arr)
    {
        return my(arr);
    }

    bool my(vector<int>& n)
    {
        sort(n.begin(), n.end(), [](int a, int b) {
            if(a > 0 && b > 0) // descending if > 0
                return a > b;
            else if(a < 0 && b < 0) // ascending if < 0
                return a < b;
            return a < b;
        });
        DBG(n);
        set<int> s;
        for(const auto &v : n)
        {
            if(s.count(v*2))
                return true;
            s.insert(v);
        }
        return false;
    }
};

int main()
{
    vector<int> v = {-10,12,-20,-8,15};
    cout << Solution{}.checkIfExist(v);
}