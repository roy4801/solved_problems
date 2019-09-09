/*
 * UVA 202 - Repeating Decimals
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "202"
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
#define N 3000
int a, b;
int d[55], cnt;
bool r[N+5];
vector<int> rr;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	rr.reserve(N+5);
	while(cin >> a >> b)
	{
		cnt = 0;
		memset(r, 0, sizeof(r));
		rr.clear();
		//
		printf("%d/%d = %d.", a, b, a/b);
		a %= b;
		rr.PB(a);
		while(!r[a])
		{
			r[a] = true;
			a *= 10;

			if(cnt < 50)
				d[cnt] = a / b;
			cnt++;

			a %= b;
			rr.PB(a);
		}

		int nc = 0; // len of not in cycle
		for(int i = 0; i < cnt && i < 50; i++)
		{
			if(rr[i] == a)
			{
				nc = i;
				putchar('(');
			}
			printf("%d", d[i]);
		}
		if(cnt >= 50) printf("...");
		puts(")");
		printf("   %d = number of digits in repeating cycle\n", cnt - nc);
		puts("");
	}

	return 0;
}
