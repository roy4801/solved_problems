/*
 * Leetcode Medium 341. Flatten Nested List Iterator
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

class NestedIterator {
public:
    vector<int> v;
    int cur = 0;
    void flatten(vector<NestedInteger> &list)
    {
        for(auto i : list)
        {
            if(i.isInteger())
            {
                v.push_back(i.getInteger());
            }
            else
            {
                flatten(i.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten(nestedList);
    }

    int next()
    {
        return v[cur++];
    }

    bool hasNext()
    {
        return cur < v.size();
    }
};

int main()
{
    // skip
}
