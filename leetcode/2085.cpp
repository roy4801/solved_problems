/*
 * Leetcode Easy 2085. Count Common Words With One Occurrence
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

    int countWords(vector<string>& a, vector<string>& b)
    {
        unordered_map<string, int> ma, mb;
        for(auto& s : a) ma[s]++;
        for(auto& s : b) mb[s]++;

        int ans = 0;
        for(auto& [s, cnt] : ma)
        {
            if(cnt == 1)
            {
                ans += mb[s] == 1;
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}
