/*
 * UVA 1234 - RACING
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1234"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second

#define M 100000
int n, m; // vertice, edge

struct Edge
{
	int fr, to, wei;
	friend bool operator<(Edge &lhs, Edge &rhs)
	{
		return lhs.wei < rhs.wei;
	}
};

Edge e[M];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int cases;
	cin >> cases;

	while(cases-- && cin >> n >> m)
	{
		for(int i = 0; i < m && cin >> e[i].fr >> e[i].to >> e[i].wei; i++);

		sort(e, e+m);

		for(int i = 0; i < m; i++)
			cout << e[i].fr << ' ' << e[i].to << ' ' << e[i].wei << '\n';
	}

	return 0;
}