/*
 * Leetcode Medium 167. Two Sum II - Input Array Is Sorted
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

class Solution
{
public:
    int bs(vector<int> &A, int L, int R, int v)
    {
        while(L < R)
        {
            int mid = (L+R)/2;
            if(v <= A[mid])
                R = mid;
            else
                L = mid+1;
        }
        return L;
    }
    
    vector<int> twoSum(vector<int>& n, int t)
    {
        vector<int> ans;
        for(int i = 0; i < n.size(); i++)
        {
            //int a = bs(n, 0, i, t-n[i]);
            int b = bs(n, i+1, n.size(), t-n[i]);
            if(b < n.size() && n[b] == t-n[i])
            {
                ans.push_back(i+1);
                ans.push_back(b+1);
                goto end;
            }
        }
    end:
        return ans;
    }
};

int main()
{
    vector<int> v = {1,3,4,4};
    int t = 8;
    auto x = Solution{}.twoSum(v, t);
    DBG(x);
}