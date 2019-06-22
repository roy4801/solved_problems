/*
 * UVA 10004 - Bicoloring
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10004"
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
#define N 200
bool G[N+5][N+5];
int n, m; // node, edge
int a, b;
int color[N+5]; // 0, 1
bool dfs(int nd, int col) // node, color
{
	bool ans = true;

	if(color[nd] != -1)
		return color[nd] == col;
	color[nd] = col;

	for(int i = 0; i < n; i++)
		if(G[nd][i])
			ans &= dfs(i, (col+1) % 2);
	return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int cnt = 1;
	#define CASE 79
	while(cin >> n && n && cin >> m)
	{
		memset(color, -1, sizeof(color));
		memset(G, 0, sizeof(G));

		for(int i = 0; i < m && cin >> a >> b; i++)
		{
			G[a][b] = true;
			G[b][a] = true;
		}

		if(dfs(0, 0))
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}

	return 0;
}
