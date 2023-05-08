/*
 * Leetcode Medium 2336. Smallest Number in Infinite Set
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

class SmallestInfiniteSet {
public:
    vector<int> v;
    set<int> s;

    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++)
        {
            v.push_back(i);
            s.insert(i);
        }
        make_heap(v.begin(), v.end(), greater<int>());
    }
    
    int popSmallest() {
        int n = 0;
        if(!v.empty())
        {
            pop_heap(v.begin(), v.end(), greater<int>());
            n = v.back();
            s.erase(n);
            v.pop_back();
        }
        return n;
    }
    
    void addBack(int num) {
        if(!s.count(num))
        {
            v.push_back(num);
            push_heap(v.begin(), v.end(), greater<int>());
            s.insert(num);
        }
    }
};

int main()
{
    // skip
}
