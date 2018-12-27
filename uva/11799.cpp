/*
 * Uva 11799 - Horror Dash
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11799.in", "r", stdin);
	freopen("./testdata/11799.out", "w", stdout);
	#endif
	int cases, scare;

	scanf("%d", &cases);

	for(int i = 1; i <= cases && scanf("%d", &scare) != EOF; i++)
	{
		int speed, max = -1;

		for(int j = 0; j < scare; j++)
		{
			scanf("%d", &speed);

			if(max < speed)
				max = speed;
		}

		printf("Case %d: %d\n", i, max);
	}

	return 0;
}