/*
 * Leetcode Medium 1535. Find the Winner of an Array Game
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

class Solution
{
public:
    int getWinner(vector<int>& arr, int k)
    {
        int ans = 0, w = 0;
        if(arr.size() <= k)
        {
            ans = *max_element(arr.begin(), arr.end());
        }
        else
        {
            int m = max(arr[0], arr[1]);
            w = 1;
            for(int i = 2; i < arr.size(); i++)
            {
                if(w >= k)
                {
                    return m;
                }

                if(arr[i] > m)
                {
                    m = arr[i];
                    w = 1;
                }
                else
                {
                    w++;
                }
            }
            ans = m;
        }
        return ans;
    }
};

int main()
{
    using InputType=pair<vector<int>,int>;
    vector<InputType> v = {
        { {1, 25, 35, 42, 68, 70}, 1 },
        { {1, 25, 35, 42, 68, 70}, 2 },
    };
    for(auto& [arr, k] : v)
        DBG(Solution{}.getWinner(arr, k));
}