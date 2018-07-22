/*
 * Uva 12468 - Zapping
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12468.in", "r", stdin);
	freopen("./testdata/12468.out", "w", stdout);
	#endif
	int cur, to;

	while(scanf("%d %d", &cur, &to) != EOF && cur != -1 && to != -1)
	{
		int distance = abs(cur - to);
		printf("%d\n", min(distance, 100 - distance));
	}

	return 0;
}