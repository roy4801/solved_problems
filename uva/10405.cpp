/*
 * UVA 10405 - Longest Common Subsequence
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10405"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define N 1000
int dp[N+5][N+5];
int a, b;
string ina, inb;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	USE_CPPIO();
	while(getline(cin, ina) && getline(cin, inb))
	{
		memset(dp, 0, sizeof(dp));
		a = ina.length(), b = inb.length();

		for(int i = 1; i <= a; i++)
			for(int j = 1; j <= b; j++)
				dp[i][j] = ina[i-1]==inb[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);

		cout << dp[a][b] << '\n';
	}

	return 0;
}
