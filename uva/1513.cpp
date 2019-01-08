/*
 * UVA 1513 - Movie collection
 * author: roy4801
 * AC(C++) 0.290
 */
#include <bits/stdc++.h>

using namespace std;
// #BIT #RMQ
#define PROB "1513"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
#define N 200000
int n, m;
int pos[N+5];

#define lowbit(x) ((x)&-(x))
int BIT[N+5];
void add(int x, int v)
{
	while(x <= N)
	{
		BIT[x] += v;
		x += lowbit(x);
	}
}
int sum(int ri)
{
	int sum = 0;
	while(ri > 0)
	{
		sum += BIT[ri];
		ri -= lowbit(ri);
	}
	return sum;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int cases;
	cin >> cases;
	while(cases-- && cin >> n >> m)
	{
		memset(BIT, 0, sizeof(BIT));
		//
		for(int i = 1; i <= n; i++)
		{
			pos[i] = m + i;
			add(pos[i], 1);
		}
		int left = m;
		int x;
		for(int i = 0; i < m && cin >> x; i++)
		{
			printf(i==m-1?"%d\n":"%d ", sum(pos[x]-1));
			add(pos[x], -1);
			pos[x] = left--;
			add(pos[x], 1);
		}
	}

	return 0;
}