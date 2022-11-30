/*
 * Leetcode Easy 1207. Unique Number of Occurrences
 * author: roy4801
 * AC(C++) 0.7ms
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution {
public:
    int N[2005] = {0}; // num+1000 => num of occur
    bool th[2005] = {0};
    bool uniqueOccurrences(vector<int>& arr)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            N[arr[i]+1000]++;
        }
        
        for(int i = 0; i <= 2001; i++)
        {
            if(N[i])
            {
                if(th[N[i]])
                    return false;
                th[N[i]] = true;;
            }
        }
        return true;
    }
};

int main()
{
    // skip
}