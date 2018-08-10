/*
 * Uva 10324 - Zeros and Ones
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstdint>
#include <climits>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10324.in", "r", stdin);
	freopen("./testdata/10324.out", "w", stdout);
	#endif
	int g[1000001];
	int a, b, cases;
	char c, prev;
	int cCase = 1;

	while((c = getchar()) != EOF)
	{
		int now = 0, gCount = 0;

		printf("Case %d:\n", cCase++);

		prev = c;
		g[now++] = gCount;

		while((c = getchar()) != EOF && c != '\n')
		{
			if(c != prev)
			{
				gCount++;
			}

			g[now++] = gCount;

			prev = c;
		}
		
		// for(int i = 0; i < now; i++)
		// {
		// 	printf("%d\n", g[i]);
		// }

		// Input the number pair
		scanf("%d", &cases);

		while(cases-- && scanf("%d %d ", &a, &b) != EOF)
		{
			// printf("%d %d\n", a, b);
			if(g[a] == g[b])
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}

	return 0;
}