/*
 * Leetcode Easy 2037. Minimum Number of Moves to Seat Everyone
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
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += abs(seats[i] - students[i]);
        return ans;
    }
};

int main()
{
    // skip
}