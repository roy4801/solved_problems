/*
 * ZEOJ a982 - 迷宮問題#1
 * author: roy4801
 * AC(C++) 4ms
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "a982"
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
#define N 100

char m[N+5][N+5];
int n;

int dir[][2] = {
				{0, -1}, // up
				{0, 1},  // down
				{-1, 0}, // left
				{1, 0}   // right
			   };

int d[N+5][N+5];
void bfs(int i, int j)
{
	queue<P> q;
	q.emplace(i, j);
	
	d[i][j] = 1;

	while(!q.empty())
	{
		// cout << ">> " << '\n';
		P cur = q.front(); q.pop();
		// dir
		for(int ii = 0; ii < 4; ii++)
		{
			int ti = cur.F + dir[ii][0], tj = cur.S + dir[ii][1];
			// cout << "dir " << ii << ' ' << ti << ' ' << tj << '\n';
			if(m[ti][tj] != '#' && d[ti][tj] == INF)
			{
				// cout << ">> in" << '\n';
				d[ti][tj] = d[cur.F][cur.S]+1;
				q.emplace(ti, tj);
			}
		}
	}
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n)
	{
		getchar();
		// init
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= N; j++)
				d[i][j] = INF;
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				cin >> m[i][j];
			getchar();
		}

		// for(int i = 1; i <= n; i++)
		// {
		// 	for(int j = 1; j <= n; j++)
		// 		putchar(m[i][j]);
		// 	putchar('\n');
		// }

		bfs(2, 2);

		// for(int i = 1; i <= n; i++)
		// {
		// 	for(int j = 1; j<= n; j++)
		// 		printf("%3d", d[i][j] == INF ? -1 : d[i][j]);
		// 	putchar('\n');
		// }
		if(d[n-1][n-1] == INF)
			printf("No solution!\n");
		else
			printf("%d\n", d[n-1][n-1]);
	}

	return 0;
}