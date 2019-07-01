/*
 * UVA 11572 - Unique Snowflakes
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11572"
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
#define N 1000000
int in[N+5];
int kase, n, tmp;
int l, r, ans;
map<int, bool> m;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n)
	{
		m.clear();
		ans = 0;
		l = r = 0;
		// input
		for(int i = 0; i < n && cin >> in[i]; i++);
		// sliding window
		while(r < n)
		{
			if(!m.count(in[r])) // not in map
			{
				m[in[r]] = true;
				ans = max(ans, r-l+1);
				r++;
			}
			else
			{
				while(m.count(in[r]))
				{
					m.erase(in[l]);
					l++;
				}
			}

			// printf("%d %d %d %d\n", l, r, in[l], in[r]);
		}

		cout << ans << '\n';
	}
	return 0;
}