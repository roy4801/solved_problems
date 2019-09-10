/*
 * UVA 275 - Expanding Fractions
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "275"
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
#define N 1000
int a, b, cnt;
bool r[N+5];
vector<int> v;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> a >> b && (a || b))
	{
		memset(r, 0, sizeof(r));
		v.clear();
		cnt = 1;
		//
		putchar('.');
		while(a)
		{
			r[a] = true;
			a *= 10;
			printf("%d", a / b);
			if(++cnt % 50 == 0)
				putchar('\n');
			a %= b;

			if(r[a])
				break;
			v.PB(a);
		}
		if(cnt % 50 != 0) putchar('\n');
		int c = 1;
		for(auto i = v.rbegin(); i != v.rend(); i++)
		{
			if(*i == a) break;
			c++;
		}
		if(a)
			printf("The last %d digits repeat forever.\n", c);
		else
			puts("This expansion terminates.");
		puts("");
	}

	return 0;
}
