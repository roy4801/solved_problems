/*
 * Leetcode Easy 520. Detect Capital
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
    bool detectCapitalUse(string s) {
        // 0 pre capital
        // 1 lower
        // 2 all capital
        // 3 only first capital
        int state = -1;

        if(islower(s[0]))
            state = 1;
        else
            state = 0;

        for(int i = 1; i < s.size(); i++)
        {
            switch(state)
            {
                case 1:
                    if(!islower(s[i]))
                        goto end;
                break;
                
                case 0:
                    if(islower(s[i]))
                        state = 3;
                    else
                        state = 2;
                break;

                case 3:
                    if(!islower(s[i]))
                        goto end;
                break;

                case 2:
                    if(islower(s[i]))
                        goto end;
                break;
            }
        }

        return true;
end:
        return false;
    }
};

int main()
{
    vector<string> in = {
        "USA",
        "FlaG",
    };
    for(auto s : in)
    {
        DBG(Solution{}.detectCapitalUse(s));
    }
}