/*
 * Uva 1605 - Building for UN
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/1605.in", "r", stdin);
	freopen("./testdata/1605.out", "w", stdout);
	#endif
	int c;
	const char *ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx";
	while(scanf("%d", &c) != EOF)
	{
		printf("2 %d %d\n", c, c);

		for(int i = 0; i < c; i++)
		{
			for(int a = 0; a < c; a++)
				putchar(ch[i]);
			putchar('\n');
		}
		putchar('\n');
		for(int i = 0; i < c; i++)
		{
			for(int a = 0; a < c; a++)
				putchar(ch[a]);

			putchar('\n');
		}
	}

	return 0;
}