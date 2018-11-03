/*
 * UVA 908 - Re-connecting Computer Sites
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

// nude minimum spanning tree

using namespace std;

#define PROB "908"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define V 1000000

// disjoint set
int p[V];
void init() {for(int i = 0; i < V; i++) p[i] = i; }
int find(int x) { return p[x] == x ? x : (p[x] = find(p[x])); }
void uni(int a, int b) { p[find(a)] = find(b); }

int n, m; // vertice, edges

struct edge
{
	int fr, to, wei;
	edge(int f, int t, int w) { fr = f; to = t; wei = w; }
	friend bool operator<(edge &lhs, edge &rhs)
	{
		return lhs.wei < rhs.wei;
	}
};

vector<edge> e;

int kruskal()
{
	init();

	sort(e.begin(), e.end());

	int total = 0, i, j;
	for(i = 0, j = 0; i < n-1 && j < e.size(); i++, j++)
	{
		while(find(e[j].fr) == find(e[j].to))
			j++;

		uni(e[j].fr, e[j].to);

		total += e[j].wei;
	}

	return total;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int fr, to, wei;
	bool first = true;
	while(cin >> n)
	{
		if(!first) putchar('\n');
		for(int i = 0; i < n-1 && cin >> fr >> to >> wei; i++)
			e.emplace_back(fr, to, wei);

		cout << kruskal() << '\n';

		cin >> m;
		for(int i = 0; i < m && cin >> fr >> to >> wei; i++)
			e.emplace_back(fr, to, wei);


		cin >> m;
		for(int i = 0; i < m && cin >> fr >> to >> wei; i++)
			e.emplace_back(fr, to, wei);

		cout << kruskal() << '\n';

		first = false;
		e.clear();
	}
	return 0;
}