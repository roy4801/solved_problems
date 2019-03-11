/*
 * ZEOJ a290 - 新手訓練系列 ~ 圖論
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "a290"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define N 800
#define M 1000000
vector<int> G[N+5];
int n, m;
bitset<N> vis;
void dfs(int s)
{
	vis[s] = 1;
	for(int i : G[s])
		if(!vis[i])
			dfs(i);
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	USE_CPPIO(); // stuck
	int fr, to;
	int a, b;
	while(cin >> n >> m)
	{
		for(int i = 1; i <= N; i++) G[i].clear();
		for(int i = 0; i < m && cin >> fr >> to; i++)
			G[fr].PB(to);
		cin >> a >> b;

		vis.reset();
		dfs(a);

		if(vis[b])
			cout << "Yes!!!" << '\n';
		else
			cout << "No!!!" << '\n';
	}
	return 0;
}
