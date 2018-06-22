/*
 * Uva 13178 - Is it multiple of 3?
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/13178.in", "r", stdin);
	freopen("./testdata/13178.out", "w", stdout);
	#endif
	int cases, n;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &n) != EOF)
	{
		long long int sum = ((1 + n)%3 * n%3 ) / 2;

		if(sum % 3 == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}