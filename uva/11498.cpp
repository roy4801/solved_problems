/*
 * Uva 11498 - Division of Nlogonia
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11498.in", "r", stdin);
	freopen("./testdata/11498.out", "w", stdout);
	#endif
	int num;

	while(scanf("%d", &num) != EOF && num)
	{
		int div[2], x, y;

		scanf("%d %d", &div[0], &div[1]);

		while(num-- && scanf("%d %d", &x, &y) != EOF)
		{
			if(x == div[0] || y == div[1])
			{
				printf("divisa\n");
			}
			else if(x > div[0] && y > div[1])
			{
				printf("NE\n");
			}
			else if(x > div[0] && y < div[1])
			{
				printf("SE\n");
			}
			else if(x < div[0] && y > div[1])
			{
				printf("NO\n");
			}
			else if(x < div[0] && y < div[1])
			{
				printf("SO\n");
			}
		}
	}

	return 0;
}