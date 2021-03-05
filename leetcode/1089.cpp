/*
 * Leetcode Easy 1089. Duplicate Zeros
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        queue<int> q;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            if(!q.empty())
            {
                q.push(arr[i]);    // because it's in-place
                arr[i] = q.front();
                q.pop();
            }
            if(arr[i] == 0)
            {
                q.push(arr[i+1]);
                arr[i+1] = 0;
                i++;
            }
        }
    }
};

// class Solution
// {
// public:
//     void duplicateZeros(vector<int> &arr)
//     {
//         int n = arr.size();
//         bool pass = false;
//         for (int i = 0; i < n; i++)
//         {
//             if(!arr[i] && !pass)
//             {
//                 pass = true;
//                 for(int j = n-1; j >= i+1; j--)
//                 {
//                     arr[j] = arr[j-1];
//                 }
//             }
//             else
//                 pass = false;
//         }
//     }
// };

int main()
{
    vector<int> v = {1, 0, 2, 3, 0, 4, 5, 0};
    Solution{}.duplicateZeros(v);
    print(v);
}