/*
 * Leetcode Easy 168. Excel Sheet Column Title
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
    string convertToTitle(int n)
    {
        string ans;
        while(n)
        {
            n--;
            ans += 'A'+(n % 26);
            n = n / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    // skip
}