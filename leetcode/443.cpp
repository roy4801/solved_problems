/*
 * Leetcode Medium 443. String Compression
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

class Solution {
public:
    int compress(vector<char>& s) {
        int ans = 0;
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 1;
        int k = 0;
        char cur = s[0];

        auto cd = [](int n)
        {
            int ans = 0;
            while(n)
            {
                n /= 10;
                ans++;
            }
            return ans;
        };

        auto calc = [&]() {
            int digit = cd(cnt);
            if(cnt > 1)
            {
                ans += 1+digit;

                s[k++] = cur;
                for(int a = digit; a >= 1; a--)
                {
                    int t = (int)pow(10, a-1);
                    char c = '0' + (cnt / t);

                    if(k < n)
                        s[k++] = c;
                    else
                        s.push_back(c);
                    
                    cnt %= t;
                }
            }
            else
            {
                ans += 1;
                s[k++] = cur;
            }
        };

        while(++j < n)
        {
            if(s[j-1] != s[j])
            {
                calc();
                cnt = 1;
                i = j;
                cur = s[i];
            }
            else
            {
                cnt++;
            }
        }
        calc();

        while(s.size() > ans)
            s.pop_back();
        
        return ans;
    }
};

int main()
{
    vector<vector<char>> in = {
        {'a','a','a','b','b','a','a'},
        {'a','a','b','b','c','c','c'},
        {'a'},
        {'a','b','b','b','b','b','b','b','b','b','b','b','b'},
        {'a','a','a','a','a','a','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','c','c','c','c','c','c','c','c','c','c','c','c','c','c'},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.compress(i));
    }
}