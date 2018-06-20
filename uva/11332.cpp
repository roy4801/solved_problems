/*
 * Uva 11332 - Summing Digits
 * author: roy4801
 * AC(C++) 0.0000
 */
#include <iostream>

using namespace std;

typedef long long int int_64;

int_64 digitSum(int_64 num)
{
	int_64 sum = 0;

	while(num > 9)
	{
		sum += num % 10LL;
		num /= 10LL;
	}
	sum += num;

	return sum;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11332.in", "r", stdin);
	freopen("./testdata/11332.out", "w", stdout);
	#endif
	int_64 n;

	while(scanf("%lld", &n) != EOF && n != 0LL)
	{
		// int_64 g = n;
		while((n = digitSum(n)) > 9LL);

		printf("%lld\n", n);
	}

	return 0;
}