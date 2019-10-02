/*
 * UVA 1442 - Cav
 * author: roy4801
 * AC(C++) 0.280
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1442"
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
#define N 1000000
int kase, n;
int lo[N+5], hi[N+5]; // floor and ceiling
int l[N+5], r[N+5];   // highest possible oil (from left or right)
int cur;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n)
	{
		memset(lo, 0, sizeof(lo));
		memset(hi, 0, sizeof(hi));

		for(int i = 0; i < n && cin >> lo[i]; i++);
		for(int i = 0; i < n && cin >> hi[i]; i++);
		// left
		cur = hi[0];
		for(int i = 0; i < n-1; i++)
		{
			l[i] = cur;
			// The next floor is higher than the current
			if(lo[i+1] > cur)
				cur = lo[i+1];
			// The next ceiling is lower than the current
			else if(hi[i+1] < cur)
				cur = hi[i+1];
		}
		l[n-1] = cur;
		// right
		cur = hi[n-1];
		for(int i = n-1; i >= 1; i--)
		{
			r[i] = cur;
			if(lo[i-1] > cur)
				cur = lo[i-1];
			else if(hi[i-1] < cur)
				cur = hi[i-1];
		}
		r[0] = cur;

		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += min(l[i], r[i]) - lo[i];
		printf("%d\n", ans);
	}

	return 0;
}
