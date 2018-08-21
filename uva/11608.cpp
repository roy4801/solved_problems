/*
 * Uva 11608 - No Problem
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11608.in", "r", stdin);
	freopen("./testdata/11608.out", "w", stdout);
	#endif
	int prob, nowCase = 1;

	while(scanf("%d", &prob) != EOF && prob > -1)
	{
		printf("Case %d:\n", nowCase++);
		int p[12], need;

		for(int i = 0; i < 12; i++)
			scanf("%d", &p[i]);

		for(int i = 0; i < 12 && scanf("%d", &need) != EOF; i++)
		{
			if(i)
			{
				prob += p[i - 1];
			}

			if(prob - need < 0)
			{
				printf("No problem. :(\n");
			}
			else
			{
				prob -= need;
				printf("No problem! :D\n");
			}
		}
	}

	return 0;
}