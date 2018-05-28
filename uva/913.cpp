/*
 * Uva 913 - Joana and the Odd Numbers
 * author: roy4801
 * AC(c++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/913.in", "r", stdin);
	freopen("./testdata/913.out", "w", stdout);
	#endif
	long long int num;

	while(scanf("%lld", &num) != EOF)
	{
		long long int ans = 0LL, sum = 0LL;

		sum = (1 + num) * (num+1)/2 /2; // sum formula An = 2k + 1

		num = sum * 2 - 1;

		ans = (num + num-2*2) * 3 / 2; // sum formula

		printf("%lld\n", ans);
	}

	return 0;
}