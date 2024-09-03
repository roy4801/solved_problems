/*
 * Leetcode Easy 1945. Sum of Digits of String After Convert
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
    int getLucky(string s, int k)
    {
        int n = s.size();
        int num = 0;
        for(char c : s)
        {
            int i = c-'a'+1;
            num += (i % 10);
            if(i >= 10)
                num += (i / 10);
        }

        if(k == 1)
            return num;
        k--;

        while(num >= 10 && k--)
        {
            int i = num;
            num = 0;
            while(i)
            {
                num += i % 10;
                i /= 10;
            }
        }
        return num;
    }
};

int main()
{

}