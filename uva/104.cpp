/*
 * UVA 104 - Arbitrage
 * author: roy4801
 * (C++)
 */
// #include <bits/stdc++.h>
#include <iostream>


using namespace std;

#define PROB "104"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 20

int n; // currency

double d[N+5][N+5][N+5]; // 1-index
int path[N+5][N+5];      // parent

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n)
	{
		// init
		memset(path, 0, sizeof(path));
		for(int l = 1; l <= n; l++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					d[l][i][j] = 0.0;

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j)
					d[1][i][j] = 1.0;
				else
					cin >> d[1][i][j];
			}
		}

		// dp
		//
		// init
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				path[i][j] = i;

		for(int l = 2; l <= n; l++)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
				{
					for(int k = 1; k <= n; k++)
					{
						if(j == k)
							continue;

						if(d[l][i][j] < d[l-1][i][k] * d[1][k][j])
						{
							d[l][i][j] = d[l-1][i][k] * d[1][k][j];
							path[i][j] = path[k][j];
						}
					}
				}
			}
		}

		bool found = false;
		int i, j;
		for(int l = 2; l <= n; l++)
		{
			for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= n; j++)
				{
					if(d[l][i][j] > 1.01)
					{
						cout << "i= " << i << " j= " << j << '\n';
						cout << d[l][i][j] << '\n';
						found = true;
						goto print;
					}
				}
			}
		}

	print:
		if(found)
		{
			cout << i << '\n';
			cout << j << '\n';
			do
			{
				cout << path[i][j] << '\n';
				i = path[i][j];
			}
			while(path[i][j] != i);
		}
		else
		{
			puts("no arbitrage sequence exists");
		}

		
	}

	return 0;
}
