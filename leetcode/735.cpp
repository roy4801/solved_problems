/*
 * Leetcode Medium 735. Asteroid Collision
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
    bool check(vector<int>& v)
    {
        int n = v.size();
        for(int i = 0; i < n-1; i++)
            if(v[i] > 0 && v[i+1] < 0)
                return 1;
        return 0;
    }
    vector<int> solve(vector<int>& v)
    {
        int n = v.size();
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            int b = v[i];
            if(!s.empty())
            {
                int a = s.top();
                if(a > 0 && b < 0)
                {
                    s.pop();
                    if(a > abs(b))
                        s.push(a);
                    else if(a < abs(b))
                        s.push(b);
                }
                else
                    s.push(b);
            }
            else
                s.push(b);
        }

        vector<int> ans;
        while(!s.empty())
            ans.push_back(s.top()), s.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> ans;
         ans = solve(ast);

         while(check(ans))
             ans = solve(ans);

        return ans;
    }
};

int main()
{
    // skip
}
