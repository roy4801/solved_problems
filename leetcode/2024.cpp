/*
 * Leetcode Medium 2024. Maximize the Confusion of an Exam
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
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int ts = 0, fs = 0;
        int i = 0;
        int ans = INT_MIN;
        for(int j = 0; j < n; j++)
        {
            if(s[j] == 'T') ts++;
            if(s[j] == 'F') fs++;

            if(ts > k && fs > k)
            {
                if(s[i] == 'T') ts--;
                if(s[i] == 'F') fs--;
                i++;
            }

            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

int main()
{
    // skip
}
