/*
 *  C - Attack Survival
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "C"
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
#define N 100000
int n, k, q;
int t;
int sc[N+5];
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n >> k >> q)
	{
		fill(sc+1, sc+1+n, q);
		for(int i = 0; i < q && cin >> t; i++)
			sc[t]--;
		for(int i = 1; i <= n; i++)
			if(k-sc[i] <= 0)
				printf("No\n");
			else
				printf("Yes\n");
	}

	return 0;
}