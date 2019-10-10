/*
 * UVA 1213 - Sum of Different Primes
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1213"
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
#define N 1125
bool p[N+5];
vector<int> pv;
void build()
{
	// pv.PB(0);
	for(int i = 2; i <= N; i++) p[i] = true;

	for(int i = 2; i <= N; i++)
	{
		if(p[i])
		{
			pv.PB(i);
			for(int j = i+i; j <= N; j += i)
				p[j] = false;
		}
	}
}
int n, k; // n ≤ 1120 and k ≤ 14
LL dp[1125][25]; // now, num
void build_dp()
{
	dp[0][0] = 1;
	for(int k = 0; k < pv.size(); k++)
		for(int i = N; i >= pv[k]; i--)
			for(int j = 0; j <= 14; j++)
				dp[i][j] = dp[i][j] + dp[i-pv[k]][j-1];
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	build();
	build_dp();

	while(cin >> n >> k && (n || k))
	{
		printf("%lld\n", dp[n][k]);
	}
	return 0;
}