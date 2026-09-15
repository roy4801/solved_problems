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

class Solution2 {
public:
    int getdigit(int n, int i)
    {
        if(i == 0)
            return n % 10;
        return n / (int)pow(10, i) % 10;
    }
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;

        int tmp = x, d = 0;
        while(tmp)
        {
            tmp /= 10;
            d++;
        }

        for(int i = 0; i <= d/2; i++)
        {
            if(getdigit(x, i) != getdigit(x, d-1-i))
                return false;
        }
        return true;
    }
};

int main()
{
    // skip
}
