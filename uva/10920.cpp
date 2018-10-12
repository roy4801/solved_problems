/*
 * Uva 10920 - Spiral Tap
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

enum
{
	Y_SUB,
	X_SUB,
	Y_ADD,
	X_ADD,
	TOTAL_STATE
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10920.in", "r", stdin);
	freopen("./testdata/10920.out", "w", stdout);
	#endif
	int grid, n;

	while(scanf("%d %d", &grid, &n) != EOF && (grid || n))
	{
		int now = 1;
		int x = (grid + 1) / 2, y = (grid + 1) / 2;
		double t = ((sqrt(n)+1.0) / 2.0);
		// printf("%.20lf ", t);
		double tmp = t - (int)t;
		int cir = (int)t + (tmp != 0 ? 1 : 0);
		
		
		

		

		printf("Line = %d, Column = %d.\n", x, y);
	}

	return 0;
}