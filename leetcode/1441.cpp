/*
 * Leetcode Medium 1441. Build an Array With Stack Operations
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

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> ans;
        int ok = 0;
        set<int> vis(target.begin(), target.end());
        for(int i = 1; i <= n; i++)
        {
            if(vis.count(i))
            {
                ans.push_back("Push");
                ok++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }

            if(ok == vis.size())
                break;
        }
        return ans;
    }
};

int main()
{
    // skip
}
