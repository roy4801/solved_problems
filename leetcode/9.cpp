/*
 * Leetcode Easy 9. Palindrome Number
 * author: roy4801
 * (C++)
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
    bool isPalindrome(int x)
    {
        if(x < 0)
            return 0;

        const auto& digit = [&](int d)
        {
            if(d == 0)
                return x % 10;
            else
                return (x / (int)pow(10, d)) % 10;
        };
        
        int y = x, d = 0;
        while(y > 0)
        {
            d++;
            y /= 10;
        }
        
        for(int i = 0; i < d; i++)
            if(digit(i) != digit(d-1-i))
                return 0;
        return 1;
    }
};

int main()
{
    // skip
}
