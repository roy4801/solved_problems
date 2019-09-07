/*
 * HOJ 467 - 黑與白
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "467"
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
#define N 500
int kase;
int n, h, c; // people, height, color
int ans;
P p[N+5];
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n)
	{
		ans = 0;
		for(int i = 0; i < n && cin >> p[i].F >> p[i].S; i++);

		sort(p, p+n);

		
	}

	return 0;
}
