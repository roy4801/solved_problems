/*
 * UVA 11059 - Maximum Product
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11059_1"
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
#define N 18
int n;
int in[N+5];
LL dp[N+5][N+5];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int ka = 1;
	while(cin >> n)
	{
		for(int i = 0; i < n && cin >> in[i]; i++);

		for(int i = 0; i < n; i++)
			dp[i][i] = in[i];

		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				dp[i][j] = dp[i][j-1] * in[j];

		LL maxv = INT_MIN;
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
				maxv = max(maxv, dp[i][j]);

		printf("Case #%d: The maximum product is %lld.\n\n", ka++, maxv < 0 ? 0 : maxv);
	}

	return 0;
}
