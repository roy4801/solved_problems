/*
 * Leetcode Medium 380. Insert Delete GetRandom O(1)
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

class RandomizedSet
{
public:
    vector<int> v;
    unordered_map<int, int> m; // value -> index

    RandomizedSet()
    {
        srand(time(0));
        v = {};
        m = {};
    }
    bool insert(int val)
    {
        if(m.count(val))
            return 0;
        m[val] = v.size();
        v.push_back(val);
        return 1;
    }
    bool remove(int val)
    {
        if(!m.count(val))
            return 0;

        int idx = m[val];

        if(v.size()-1 >= 0)
        {
            v[idx] = v.back();
            m[v[idx]] = idx;
        }
        v.pop_back();
        m.erase(val);
        return 1;
    }
    int getRandom()
    {
        int i = rand() % v.size();
        return v[i];
    }
};

int main()
{
    // skip
}