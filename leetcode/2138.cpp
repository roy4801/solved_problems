/*
 * Leetcode Easy 2138. Divide a String Into Groups of Size k
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
    vector<string> divideString(string s, int k, char c)
    {
        int n = s.size(), cnt = 0;
        string tmp;
        vector<string> ans;
        for(int i = 0; i < n; i++)
        {
            tmp += s[i];
            cnt++;
            if(cnt >= k)
            {
                ans.push_back(tmp);
                tmp = "";
                cnt = 0;
            }
        }
        if(tmp.size())
        {
            cnt = k-tmp.size();
            for(int i = 0; i < cnt; i++)
                tmp += c;
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main()
{
    // skip
}