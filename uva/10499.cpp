/*
 * Uva 10499 - The Land of Justice
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10499.in", "r", stdin);
	freopen("./testdata/10499.out", "w", stdout);
	#endif
	int part;

	while(scanf("%d", &part) != EOF && part > 0)
	{
		printf("%lld%%\n", part == 1 ? 0LL : 50LL + 25LL * ((long long int)part - 2LL));
	}

	return 0;
}