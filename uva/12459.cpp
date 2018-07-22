/*
 * Uva 12459 - Bees' ancestors
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12459.in", "r", stdin);
	freopen("./testdata/12459.out", "w", stdout);
	#endif
	int gen;

	while(scanf("%d", &gen) != EOF && gen)
	{
		int64_t a = 1, b = 1;

		while(gen--)
		{
			a += b;
			swap(a, b);
		}

		printf("%lld\n", a);
	}

	return 0;
}