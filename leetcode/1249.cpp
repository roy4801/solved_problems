/*
 * Leetcode Medium 1249. Snapshot Array
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

#define N 100000

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        bool vis[N+5];
        vector<int> stk;
        string ans;
        
        memset(vis, true, sizeof(vis));
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                stk.push_back(i);
            else if(s[i] == ')')
            {
                if(!stk.empty())
                    stk.pop_back();
                else
                    vis[i] = false;
            }
        }

        for(int i : stk)
            vis[i] = false;

        for(int i = 0; i < s.size(); i++)
        {
            if(vis[i]) ans += s[i];
        }
        
        return ans;
    }
};

/*
lee(t(c)o)de)
a)b(c)d
))((
*/

int main()
{
    string s;
    while(cin >> s)
    {
        cout << Solution{}.minRemoveToMakeValid(s) << '\n';
    }
}