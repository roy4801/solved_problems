/*
 * UVA 1225 - Digit Counting
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1225"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define N 10000
int n, kase, tmp;
int dp[N+5][10]; // dp[i] means the cnt of 0~9 when n=i
void init()
{
	dp[1][1] = 1;
	for(int i = 2; i <= N; i++)
	{
		for(int j = 0; j < 10; j++)
			dp[i][j] += dp[i-1][j];
		tmp = i;
		while(tmp)
		{
			dp[i][tmp % 10]++;
			tmp /= 10;
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	init();
	cin >> kase;
	while(kase-- && cin >> n)
	{
		for(int i = 0; i < 10; i++)
			printf("%d%c", dp[n][i], i==9?'\n':' ');
	}

	return 0;
}