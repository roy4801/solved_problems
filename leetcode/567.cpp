/*
 * Leetcode Medium 567. Permutation in String
 * author: roy4801
 * AC(C++) 0.195 7.2MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    bool check(int a[26], int b[26])
    {
        int cnt = 0;
        for(int i = 0; i < 26; i++)
        {
            if(a[i] == b[i]) cnt++;
        }
        return cnt == 26;
    }
    
    bool checkInclusion(string a, string b)
    {
        unordered_map<string, bool> m;
        int ad[26], bd[26];
        bool ok = false;
        
        memset(ad, 0, 26 * sizeof(int));
        memset(bd, 0, 26 * sizeof(int));
        
        for(int i = 0; i < a.size(); i++)
            ad[a[i]-'a']++;

        for(int i = 0; i < max((int)(b.size() - a.size() + 1), 0); i++)
        {
            for(int j = 0; j < a.size(); j++)
                bd[b[i+j] - 'a']++;
            
            if(check(ad, bd))
            {
                ok = true;
                break;
            }
            
            memset(bd, 0, 26 * sizeof(int));
        }
        
        return ok;
    }
};

class Solution2
{
public:
    int A[26], B[26];
    bool checkInclusion(string a, string b) {
        int n = a.size(), m = b.size();
        for(char c : a)
            A[c-'a']++;

        int len = m-n+1;
        for(int i = 0; i < len; i++)
        {
            memset(B, 0, sizeof(B));
            for(int j = 0; j < n; j++)
            {
                B[b[i+j]-'a']++;
            }
            if(equal(A, A+26, B))
                return true;
        }
        return false;
    }
};

int main()
{
    cout << Solution{}.checkInclusion("ab", "eidbaooo") << '\n';
}