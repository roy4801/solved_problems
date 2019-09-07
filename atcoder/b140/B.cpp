/*
 *  B - Buffet
 * author: roy4801
 * AC(C++) 0.001
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "B"
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
#define N 20
int n;
int a[N+5], b[N+5], c[N+5];
int pre, ans;
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n)
	{
		pre = ans = 0;
		for(int i = 1; i <= n && cin >> a[i]; i++);
		for(int i = 1; i <= n && cin >> b[i]; i++);
		for(int i = 1; i <= n-1 && cin >> c[i]; i++);

		for(int i = 1; i <= n; i++)
		{
			if(pre+1 == a[i])
				ans += c[pre];
			ans += b[a[i]];
			pre = a[i];
		}
		cout << ans << '\n';
	}

	return 0;
}