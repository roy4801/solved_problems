/*
 * Uva 13187 - Felipe and the Sequence
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/13187.in", "r", stdin);
	freopen("./testdata/13187.out", "w", stdout);
	#endif
	int cases, s;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &s) != EOF)
	{
		printf("%lld\n", (int64_t)(s + 1) * (int64_t)(s + 1) - 1LL);
	}

	return 0;
}