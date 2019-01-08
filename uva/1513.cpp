/*
 * UVA 1513 - Movie collection
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1513"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
#define N 100000
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
		for(int i = 1; i <= n; i++)
		{
			pos[i] = i;
			add(i, 1);
		}
		int x;
		for(int i = 0; i < m && cin >> x; i++)
		{
			// for(int a = 1; a <= n; a++)
			// 	printf("%d ", BIT[a]);
			// puts("");
			//
			printf(i==m-1?"%d\n":"%d ", sum(pos[x])-1);
			add(pos[x], -1);
			pos[x] = ++n;
			add(pos[x], 1);
		}
	}

	return 0;
}