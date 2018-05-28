/*
 * Uva 591 - Box of Bricks
 * author: roy4801
 * AC(c++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/591.in", "r", stdin);
	freopen("./testdata/591.out", "w", stdout);
	#endif
	int tiles, sum = 0, n = 1;

	while(scanf("%d", &tiles) != EOF && tiles != 0)
	{
		printf("Set #%d\n", n++);
		int b[tiles];

		for(int i = 0; i < tiles; i++)
		{
			scanf("%d", &b[i]);
			sum += b[i];
		}
		int avg = sum / tiles;
		sum = 0;

		for(int i = 0; i < tiles; i++)
		{
			sum += b[i] > avg ? b[i] - avg : 0;
		}

		printf("The minimum number of moves is %d.\n\n", sum);
		sum = 0;
	}
	return 0;
}