/*
 * Uva 11151 - Water Shortage
 * author: roy4801
 * AC(C++) 0.010
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "11151"
#define TESTC ""
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define N 1000
int kase;
string s;
int lcs[N+5][N+5];
int main()
{
	cin >> kase; getchar();
    while(kase-- && getline(cin, s))
    {
        memset(lcs, 0, sizeof(lcs));
        //
        string r = s;
        reverse(r.begin(), r.end());
        for(int i = 1; i <= s.size(); i++)
            for(int j = 1; j <= r.size(); j++)
            {
                if(s[i-1] == r[j-1])
                    lcs[i][j] = lcs[i-1][j-1]+1;
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        printf("%d\n", lcs[s.size()][r.size()]);
    }
}