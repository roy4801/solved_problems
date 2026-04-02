/*
 * Leetcode Medium 146. LRU Cache
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

class LRUCache
{
public: 
    LRUCache(int capacity)
    {
        m_Capacity = capacity;
    }

    int get(int key)
    {
        if (m_Index.count(key))
        {
            auto value = m_Index[key]->value;
            erase(key);
            push(key, value);
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m_Index.count(key))
        {
            erase(key);
            push(key, value);
        }
        else
        {
            if (m_Cache.size() >= m_Capacity)
            {
                auto oldkey = m_Cache.front().key;
                erase(oldkey);
            }
            push(key, value);
        }
    }

private: 
    void push(int key, int value)
    {
        m_Cache.push_back({key, value});
        m_Index[key] = std::prev(m_Cache.end());
    }
    void erase(int key)
    {
        m_Cache.erase(m_Index[key]);
        m_Index.erase(key);
    }

    int m_Capacity;

    struct CacheEntry {
        int key;
        int value;
    };
    std::unordered_map < int,
    std::list < CacheEntry > ::iterator > m_Index; // key -> cache iterator
    std::list < CacheEntry > m_Cache;
};

int main()
{

}