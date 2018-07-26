/*
 * Uva 12372 - Packing for Holiday
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12372.in", "r", stdin);
	freopen("./testdata/12372.out", "w", stdout);
	#endif
	int cases, i = 1, side;

	scanf("%d", &cases);

	while(cases--)
	{
		bool fit = true;
		for(int i = 0; i < 3 && scanf("%d", &side) != EOF; i++)
		{
			if(side > 20 || side < 1)
			{
				fit = false;
			}
		}

		printf("Case %d: %s\n", i++, fit ? "good" : "bad");
	}

	return 0;
}