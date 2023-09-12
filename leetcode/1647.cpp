/*
 * Leetcode Medium 1647. Minimum Deletions to Make Character Frequencies Unique
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
    int minDeletions(string s)
    {
        int ans = 0;
        int m[26] = {0};
        int n = s.size();

        for(int i = 0; i < n; i++)
            m[s[i]-'a']++;
        sort(m, m+26, greater<int>());

        set<int> exist;
        for(int i = 0; i < 26; i++)
        {
            if(!m[i])
                continue;

            if(!exist.count(m[i]))
                exist.insert(m[i]);
            else
            {
                while(--m[i] >= 0)
                {
                    ans++;
                    if(!exist.count(m[i]))
                    {
                        exist.insert(m[i]);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    // skip
}
