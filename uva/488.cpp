/*
 * Uva 488 - Triangle Wave
 * author: roy4801
 * (C++)
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/488.in", "r", stdin);
	freopen("./testdata/488.out", "w", stdout);
	#endif

	int freq, magn;
	int times;

	if(scanf("%d", &times) != EOF)
	{
		while(times--)
		{
			scanf("%d\n%d", &magn, &freq);
			
			// I'm idiot QQ
			if(magn == 1 && freq == 1)
			{
				printf("1");
			}
			else
			{
				while(freq--)
				{
					for(int i = 0; i < magn; i++)
					{
						for(int j = 0; j < i + 1; j++)
							printf("%d", i + 1);
						putchar('\n');
					}
					for(int i = magn - 1; i > 0; i--)
					{
						for(int j = 0; j < i ; j++)
							printf("%d", i);
						if(i != 1)
							putchar('\n');
					}
					if(freq)
					{
						printf("\n\n");
					}
				}
			}
			if(times)
				printf("\n\n");
		}
	}

	return 0;
}