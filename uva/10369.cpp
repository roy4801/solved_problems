/*
 * UVA 10369 - Arctic Network
 * author: roy4801
 * AC(C++) 0.020
 */
#include <bits/stdc++.h>

// minimum spanning tree

using namespace std;

#define PROB "10369"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 500

// Point
typedef pair<int, int> P;
#define X first
#define Y second

P pt[N];

// disjoint set
int ds[N];
void init() { for(int i = 0; i < N; i++) ds[i] = i; }
int find(int i) { return ds[i] == i ? i : (ds[i] = find(ds[i])); }
void uni(int a, int b) { ds[find(a)] = find(b); }

// edge
struct edge
{
	int fr, to;
	float wei;
	edge(int f, int t, float w) {fr = f; to = t; wei = w;}
	friend bool operator<(const edge &lhs, const edge &rhs)
	{
		return lhs.wei < rhs.wei;
	}
};

vector<edge> e;
int s, p; // satellite, outpost

vector<float>& kruskal()
{
	static vector<float> res; // without copy
	init();
	res.clear();

	sort(e.begin(), e.end()); // sort

	int i, j;

	for(i = 0, j = 0; i < p-1 && j < e.size(); i++, j++)
	{
		while(find(e[j].fr) == find(e[j].to))
			j++;
		uni(e[j].fr, e[j].to);
		res.push_back(e[j].wei);
	}

	sort(res.begin(), res.end());
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	// USE_CPPIO();
	int cases;
	
	cin >> cases;
	while(cases-- && cin >> s >> p)
	{
		for(int i = 0; i < p && cin >> pt[i].X >> pt[i].Y; i++); // input

		// connect all edges
		for(int i = 0; i < p; i++)
			for(int j = i+1; j < p; j++)
			{
				e.emplace_back(i, j, sqrt(pow(abs(pt[i].X - pt[j].X), 2.f)+pow(abs(pt[i].Y - pt[j].Y), 2.f)));
			}

		auto &res = kruskal();
		// for(auto i : res)
		// 	cout << i.fr << " => " << i.to << " = " << i.wei << '\n';
		printf("%.2f\n", res[res.size()-1 - (s-1)]);
		e.clear();
	}

	return 0;
}