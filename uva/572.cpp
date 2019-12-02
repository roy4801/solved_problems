/*
 * Uva 572 - Oil Deposits
 * author: roy4801
 * AC(C++) 0.130
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "572"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define N 10000
int m, n;
int ma[N+5][N+5];
// bitset<N+5> vis[N+5];
bool vis[N+5][N+5];
int g;
//
void dfs(int i, int j, int gr)
{
	if(ma[i][j] == '*' || !ma[i][j])
	{
		ma[i][j] = 0;
		return;
	}
	// printf("> %d %d\n", i, j);
	if(!vis[i][j])
	{
		if(!gr)
			gr = g++;
		//
		ma[i][j] = gr;
		vis[i][j] = true;
		if(i-1 >= 0)
		{
			dfs(i-1, j, gr);
			if(j-1 >= 0)
				dfs(i-1, j-1, gr);
			if(j+1 <= n-1)
				dfs(i-1, j+1, gr);
		}
		if(i+1 <= m-1)
		{
			dfs(i+1, j, gr);
			if(j-1 >= 0)
				dfs(i+1, j-1, gr);
			if(j+1 <= n-1)
				dfs(i+1, j+1, gr);
		}
		if(j-1 >= 0)
			dfs(i, j-1, gr);
		if(j+1 <= n-1)
			dfs(i, j+1, gr);
	}
}
int main()
{
	while(cin >> m >> n && (m || n))
	{
		g = 1;
		memset(vis, 0, sizeof(vis));
		// for(int i = 0; i < m; i++) vis[i].reset();
		//
		for(int i = 0; i < m; i++)
		{
			getchar();
			for(int j = 0; j < n && ~scanf("%c", &ma[i][j]); j++);
		}
		//
		for(int i = 0; i < m; i++) for(int j = 0; j < n; j++)
		{
			if(!vis[i][j])
				dfs(i, j, 0);
		}
		int ans = 0;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				ans = max(ans, (int)ma[i][j]);
		printf("%d\n", ans);
	}
	return 0;
}