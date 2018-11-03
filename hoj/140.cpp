/*
 * HOJ 140 - 海綿寶寶之偷賣美味蟹堡(最小生成樹)
 * author: roy4801
 * AC(C++) 
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "140"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define V 50000
#define E 200000

// disjoint set
int ds[V];
void init() { for(int i = 0; i < V; i++) ds[i] = i; }
int find(int i) { return ds[i] == i ? i : (ds[i] = find(ds[i])); }
void uni(int a, int b) { ds[find(a)] = find(b); }

struct edge
{
	int fr, to, wei;
	void setEdge(int f, int t, int w) { fr = f; to = t; wei = w;}
	friend bool operator<(edge &lhs, edge &rhs) { return lhs.wei < rhs.wei; }
}e[E];

int n, m;  // n vertice, m edges

int kruskal()
{
	init();

	sort(e, e+m);

	int total = 0, i, j; // i -> cur vectex, j -> cur edge
	for(i = 0, j = 0; i < n-1 && j < m; i++, j++)
	{
		// if it's in the same group, skipping it.
		while(find(e[j].fr) == find(e[j].to))
			j++;

		uni(e[j].fr, e[j].to);

		total += e[j].wei;
	}

	return i == n-1 ? total : -1;
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int fr, to, wei;
    while(cin >> n >> m)
    {
    	for(int i = 0; i < m && cin >> fr >> to >> wei; i++)
    		e[i].setEdge(fr, to, wei);

    	cout << kruskal() << '\n';
    }

	return 0;
}