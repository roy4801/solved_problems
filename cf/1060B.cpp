/*
 * CF 1060B - Maximum Sum of Digits
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1060B"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long int LL;

LL sumDigit(LL n)
{
	LL s = 0;

	while(n > 9)
	{
		s += n % 10;
		n /= 10;
	}
	s += n;
	return s;
}

int getDigit(LL n)
{
	int d = 0;
	while(n > 9)
	{
		d++;
		n /= 10;
	}
	d += (n != 0 ? 1 : 0);
	return d;
}

LL pow(LL a, LL b)
{
	if(b == 0)
		return 1;
	else if(b == 1)
		return a;

	LL half = pow(a, b / 2);
	if(b % 2 != 0)
		return half * half * a;
	else
		return half * half;
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	LL n;

	while(scanf("%lld", &n) != EOF)
	{
		int digit = getDigit(n);
		LL p10_digitm1 = pow(10, digit - 1);
		int msd = n / p10_digitm1;
		LL a = msd * p10_digitm1 - 1;

		printf("%lld\n", sumDigit(a) + sumDigit(n - a));
		// printf("%d %d\n", msd, digit);
	}

	return 0;
}