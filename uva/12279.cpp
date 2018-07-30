/*
 * Uva 12279 - Emoogle Balance
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12279.in", "r", stdin);
	freopen("./testdata/12279.out", "w", stdout);
	#endif
	int event, i = 1;

	while(scanf("%d", &event) != EOF && event)
	{
		printf("Case %d: ", i++);

		int emoogle = 0, tmp;

		for(int i = 0; i < event && scanf("%d", &tmp) != EOF; i++)
		{
			if(tmp == 0)
				emoogle--;
			else if(tmp > 0)
				emoogle++;
		}

		printf("%d\n", emoogle);
	}

	return 0;
}