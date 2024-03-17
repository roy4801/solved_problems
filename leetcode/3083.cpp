/*
 * Leetcode Easy 3083. Existence of a Substring in a String and Its Reverse
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
    bool isSubstringPresent(string s)
    {
        int n = s.size();
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 2; j <= n; j++)
            {
                if(i + j <= n)
                {
                    string tmp = s.substr(i, j);
                    if(rs.find(tmp) != string::npos)
                        return 1;
                }
            }
        }
        
        return 0;
    }
};

int main()
{
    // skip
}