/*
 * UVA 1234 - RACING
 * author: roy4801
 * AC(C++) 0.150
 */
#include <bits/stdc++.h>

using namespace std;

// maxmium spanning tree

#define PROB "1234"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second

#define M 100000
int n, m; // vertice, edge

// disjoint set (1-index)
int p[M+5];
void init() { for(int i = 1; i <= n; i++) p[i] = i; }
int find(int x) { return x==p[x] ? x : (p[x] = find(p[x])); }
void uni(int a, int b) { p[find(a)] = find(b); }

struct Edge
{
	int fr, to, wei;
	friend bool operator>(const Edge &lhs, const Edge &rhs)
	{
		return lhs.wei > rhs.wei;
	}
};

Edge e[M];
bool valid[M];

void kruskal()
{
	init();
	fill(valid, valid + M, true);

	sort(e, e+m, greater<Edge>());

	// for(int i = 0; i < m; i++)
	// 	cout << e[i].fr << ' ' << e[i].to << ' ' << e[i].wei << '\n';

	int i, j;
	for(i = 0, j = 0; i < n-1 && j < m; i++, j++)
	{
		while(find(e[j].fr) == find(e[j].to)) j++;
		uni(e[j].fr, e[j].to);
		valid[j] = false;
	}
}

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

		kruskal();

		int camera = 0;
		for(int i = 0; i < m; i++)
			if(valid[i])
				camera += e[i].wei;
		cout << camera << '\n';
	}

	return 0;
}