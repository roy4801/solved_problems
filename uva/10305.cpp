/*
 * UVA 10305 - Ordering Tasks
 * author: roy4801
 * AC(C++) 0.000
 */
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define PROB "10305"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define V 100

vector<int> e[V];
int conn[V];

int n, m; // vertex, edge

vector<int> topo_sort()
{
	vector<int> res;
	for(int i = 0; i < n; i++) conn[i] = 0;

	for(int i = 0; i < n; i++)
		for(int j : e[i])
			conn[j]++;

	queue<int> q;
	for(int i = 0; i < n; i++)
		if(!conn[i])
			q.push(i);

	int i;
	for(i = 0; i < n; i++)
	{
		if(q.empty()) break;

		int f = q.front(); q.pop();

		res.push_back(f);
		conn[f] = -1;

		for(int j : e[f])
		{
			conn[j]--;
			if(!conn[j])
				q.push(j);
		}
	}

	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int fr, to;
	while(cin >> n >> m && (n || m))
	{
		for(int i = 0; i < m && cin >> fr >> to; i++)
			e[--fr].push_back(--to);

		auto res = topo_sort();

		for(int i = 0; i < res.size(); i++)
		{
			cout << res[i]+1 << (i!=res.size()-1 ? ' ' : '\n');
		}
		// clear
		for(int i = 0; i < n; i++)
			e[i].clear();
	}
	

	return 0;
}
