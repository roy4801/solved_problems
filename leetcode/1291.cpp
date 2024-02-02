/*
 * Leetcode Medium 1291. Sequential Digits
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
    vector<int> sequentialDigits(int low, int high)
    {
        set<int> ans;
        int a = log10(low)+1, b = log10(high)+1;

        for(int i = a; i <= b; i++)
        {
            char c = '1', cur = c;
            while(1)
            {
                string s;
                for(int j = 0; j < i; j++)
                {
                    s += cur;
                    cur++;
                    if(cur > '9')
                        break;
                }
                c++;
                if(c > '9')
                    break;
                cur = c;
                int num = stoi(s);
                if (low <= num && num <= high)
                    ans.insert(num);
            }
            end:
        }

        return vector<int>(ans.begin(), ans.end());
    }
};

int main()
{
    // skip
}
