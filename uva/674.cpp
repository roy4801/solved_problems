/*
 * UVA 674 - Coin Change
 * author: roy4801
 * AC(C++) 0.060
 */
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define PROB "674"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 7489
#define TYPE 5

int dp[N+5] = {1};
int val[] = {1, 5, 10, 25, 50};

void build()
{
	for(int i = 0; i < TYPE; i++)
	{
		for(int j = 0; j <= N; j++)
		{
			if(j >= val[i])
				dp[j] += dp[j - val[i]];
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	build();
	int total;

	while(cin >> total)
	{
		cout << dp[total] << '\n';
	}

	return 0;
}
