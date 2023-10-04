/*
 * Leetcode Easy 706. Leetcode Easy
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

class MyHashMap {
public:
    const int N = 1000;
    vector<list<array<int,2>>> m;
    MyHashMap()
    {
        m.resize(N+5, {});
    }
    
    void put(int key, int value)
    {
        int i = key % N;
        for(auto& j : m[i])
        {
            if(j[0] == key)
            {
                j[1] = value;
                return;
            }
        }

        m[i].push_back({key, value});
    }
    
    int get(int key)
    {
        int i = key % N;
        for(auto& j : m[i])
        {
            if(j[0] == key)
            {
                return j[1];
            }
        }
        return -1;
    }
    
    void remove(int key)
    {
        int i = key % N;
        for(auto& j : m[i])
        {
            if(j[0] == key)
            {
                m[i].remove(j);
                return;
            }
        }
    }
};

class MyHashMap2 {
public:
    const int N = 1000000;
    vector<int> m;
    MyHashMap()
    {
        m.resize(N+5, -1);
    }

    void put(int key, int value)
    {
        m[key] = value;
    }

    int get(int key)
    {
        return m[key];
    }

    void remove(int key)
    {
        m[key] = -1;
    }
};

int main()
{
    // skip
}
