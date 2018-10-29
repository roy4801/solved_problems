/*
 * TOJ 13 - 背包
 * author: roy4801
 * AC(C++) 0.030
 */
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define PROB "13"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define M 100000
#define N 100

int bag[2][M+1];
int v, n; // volume, number of items
int w, p; // weight, price

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> v >> n)
	{
		for(int a = 0; a < n && cin >> w >> p; a++)
		{
			for(int i = 0; i <= v; i++)
			{
				if(i - w >= 0)
					bag[1][i] = max(bag[1][i - w] + p, bag[0][i]);
				else
					bag[1][i] = bag[0][i];
			}

			for(int i = 0; i <= v; i++)
				bag[0][i] = bag[1][i];

		}
		cout << bag[1][v] << '\n';
		memset(bag, 0, sizeof(bag));
	}


	return 0;
}
