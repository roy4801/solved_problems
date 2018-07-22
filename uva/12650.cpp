/*
 * Uva 12650 - Dangerous Dive
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12650.in", "r", stdin);
	freopen("./testdata/12650.out", "w", stdout);
	#endif
	int total, rt, tmp;

	while(scanf("%d %d", &total, &rt) != EOF)
	{
		if(total != rt)
		{
			bool people[total];

			memset(people, 0, total * sizeof(bool));

			for(int i = 0; i < rt && scanf("%d", &tmp) != EOF; i++)
				people[tmp-1] = true;

			for(int i = 0; i < total; i++)
				if(!people[i])
					printf("%d ", i+1);
		}
		else
		{
			printf("*");
			for(int i = 0; i < rt; i++)
				scanf("%d", &tmp);
		}
		putchar('\n');
	}

	return 0;
}