/*
 * Leetcode Medium 165. Compare Version Numbers
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    void split(string &s, vector<int> &n)
    {
        int cur = 0;
        for(char c : s)
        {
            if(c == '.')
            {
                n.push_back(cur);
                cur = 0;
                continue;
            }
            cur *= 10;
            cur += c - '0';
        }

        n.push_back(cur);
    }
    
    // >
    int compareVersion(string a, string b)
    {
        vector<int> A, B;
        
        split(a, A);
        split(b, B);

        puts("FUCK");
        
        vector<int> *p = nullptr;
        int siz = max(A.size(), B.size());
        if(A.size() != siz)
            p = &A;
        else if(B.size() != siz)
            p = &B;
        if(p)
        {
            vector<int> &v = *p;

            for(int i = v.size(); i < siz; i++)
                v.push_back(0);
        }

        DBG(A);
        DBG(B);

        int i;
        for(i = 0; i < siz; i++)
        {
            if(A[i] != B[i])
                break;
        }

        return i == siz ? 0 : (A[i]>B[i] ? 1 : -1);
    }
};

int main()
{
    string a = "1.01";
    string b = "1.001";
    cout << Solution{}.compareVersion(a, b) << '\n';
}