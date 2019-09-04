/*
 * HOJ 466 - 蚯蚓王
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "466"
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
#define PPB pop_back
#define PF push_front
#define PPF pop_front
int kase, n, tmp;
map<int, int> m;
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n)
	{
		priority_queue<P> pq;
		m.clear();

		for(int i = 0; i < n && cin >> tmp; i++)
		{
			if(!m.count(tmp))
				m[tmp] = 1;
			else
				m[tmp]++;
		}
		for(auto &i : m)
			pq.push(MP(i.S, i.F));

		auto a = pq.top(); pq.pop();
		if(a.F > n/2)
			printf("%d\n", a.S);
		else
			printf("-1\n");
	}

	return 0;
}
