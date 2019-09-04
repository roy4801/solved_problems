/*
 * HOJ 457 - 好吃的麵包
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "457"
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
int kase;
int n, x, y, m;
int a, b;
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n >> x >> y >> m)
	{
		a = (n - m*y)/(x-y);
		b = (n - m*x)/(y-x);
		printf("%d %d\n", a, b);
	}

	return 0;
}
