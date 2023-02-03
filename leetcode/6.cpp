/*
 * Leetcode Medium 6. Zigzag Conversion
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
    string convert(string s, int m) {
        int n = s.size();
        vector<string> tmp(m);

        if(m >= n || m == 1)
            return s;

        int a = n / m, b = n % m; // a = 7 字形有幾組, b = 剩下幾個數字 [0, m)
        const int siz = m + (m-2); // 正序有 m 個數字，zigzag 有 m-2 個數字

        auto process = [&](int start, int end)
        {
            for(int i = start; i < end; i++)
            {
                if(i >= n)
                    continue;

                int j = i-start;
                if(j >= m) // 處理 zigzag 斜斜的部分
                {
                    // (j%m) 把值壓在 [0, m)
                    // m-2 = m-1 -1 => 倒數第二格, 整個意思是從倒數第二格開始往前 (j%m) 格
                    tmp[m-2 - (j%m)] += s[i];
                }
                else
                {
                    tmp[j] += s[i]; // 正序
                }
            }
        };

        for(int k = 0; k < a; k++)
        {
            int start = siz * k;
            int end = siz * (k+1);
            process(start, end);
        }

        int start = siz * a;
        process(start, start+b);
        
        string ans;
        for(int i = 0; i < m; i++)
            ans += tmp[i];
        return ans;
    }
};

int main()
{
    vector<pair<string, int>> in = {
        {"PAYPALISHIRING", 1},
        {"PAYPALISHIRING", 2},
        {"PAYPALISHIRING", 3},
        {"PAYPALISHIRING", 4},
        {"A", 1},
        {"A", 2},
        {"ABC", 2},
    };
    for(auto &i : in)
    {
        DBG(Solution{}.convert(i.X, i.Y));
    }
}