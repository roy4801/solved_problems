/*
 * UVA 147 - Dollars
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "147"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 30000

typedef long long LL;

//  $100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c
int d[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
LL dp[N+5] = {1};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	for(int i = 0; i < 11; i++)
	{
		for(int j = d[i]; j <= N; j++)
		{
			dp[j] += dp[j - d[i]];
		}
	}

	double in;
	while(cin >> in && in != 0.0)
	{
		printf("%6.2lf%17lld\n", in, dp[(int)round(in*100)]);
	}

	return 0;
}