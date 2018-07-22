/*
 * Uva 13185 - DPA Numbers I
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/13185.in", "r", stdin);
	freopen("./testdata/13185.out", "w", stdout);
	#endif
	int cases, num;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &num) != EOF)
	{
		int sum = 1;

		for(int i = 2; i < num; i++)
		{
			sum += num % i == 0 ? i : 0;
		}

		if(num == sum)
			printf("perfect\n");
		else if(num < sum)
			printf("abundant\n");
		else if(num > sum)
			printf("deficient\n");
	}

	return 0;
}