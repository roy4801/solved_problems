/*
 * UVA 1587 - Box
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1587"
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
#define N 10000
vector<P> l;
map<int, int> m;
int grp = 1;
int a, b, c;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int cnt = 0;
	while(cin >> a >> b)
	{
		l.PB(MP(min(a,b), max(a,b)));
		if(!m.count(a)) m[a] = grp++;
		if(!m.count(b)) m[b] = grp++;
		cnt++;

		if(cnt == 6)
		{
			a = b = c = 0;
			for(auto i : l)
			{
				int l = min(m[i.F], m[i.S]), r = max(m[i.F], m[i.S]);
				// cout << l << ' ' << r << '\n';
				if(l == 1 && r == 2)
					a++;
				else if((l == 1 && r == 3)
					|| (l == 2 && r == 3))
					b++;
				else if(l == 1 && r == 1)
					c++;
			}

			// printf("a=%d b=%d c=%d\n", a, b, c);

			if((a == 2 && b == 4) || grp == 2 || (a == 4 && c == 2))
				puts("POSSIBLE");
			else
				puts("IMPOSSIBLE");

			cnt = 0;
			l.clear();
			m.clear();
			grp = 1;
		}
	}

	return 0;
}
