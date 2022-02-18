/*
 * Leetcode Medium 402. Remove K Digits
 * author: roy4801
 * AC(C++) 4ms 7.1MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution {
public:
    string removeKdigits(string num, int k)
    {
        string ans;
        
        for(char c : num)
        {
            // if current digit is greater than the previous digit, deletes it
            while(!ans.empty() && ans.back() > c && k)
            {
                ans.pop_back();
                k--;
            }
            
            ans.push_back(c);
        }
        // if the nums are monotone ascending, delete digits from back
        while(k--)
            ans.pop_back();
        
        // Remove the leading zeros 
        int start = 0;
        while(ans[0] == '0' && ans[start] == '0')
            start++;
        ans = ans.substr(start, ans.size()-start);
        
        return ans == "" ? "0" : ans;
    }
};

int main()
{
    string s = "1234567890";
    int k = 9;
    cout << Solution{}.removeKdigits(s, k) << '\n';
}