/*
 * Uva 457 - Linear Cellular Automata
 * author: roy4801
 * AC(c++)
 */
#include <iostream>

using namespace std;

#define DAY 50

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/457.in", "r", stdin);
	freopen("./testdata/457.out", "w", stdout);
	#endif
	const char printChar[4] = { ' ', '.', 'x', 'W' };

	int cases;


	scanf("%d ", &cases);
	// printf("%d", cases);

	while(cases--)
	{
		int dna[10];
		char dish[2][40] = {0};
		int nowDish = 0;

		for(int i = 0; i < 10; i++)
		{
			scanf("%d", &dna[i]);
			// dna[i] -= '0';
		}

		// grow for 50 days
		for(int i = 0; i < DAY; i++)
		{
			if(i == 0)
			{
				dish[nowDish][19] = 1; //first day
			}
			else
			{
				// grow
				int tmp;
				int edit = (nowDish + 1) % 2;

				for(int a = 0; a < 40; a++)
				{
					if(a == 0)
					{
						tmp = dish[nowDish][a] + dish[nowDish][a+1];
					}
					else if (a == 39)
					{
						tmp = dish[nowDish][a-1] + dish[nowDish][a];
					}
					else
					{
						tmp = dish[nowDish][a-1] + dish[nowDish][a] + dish[nowDish][a+1];
					}

					// new dish arr
					dish[edit][a] = dna[tmp];
				}
				nowDish = edit;
			}

			// print
			for(int a = 0; a < 40; a++)
			{
				putchar(printChar[ dish[nowDish][a] ]);
			}
			putchar('\n');
		}

		if(cases)
			putchar('\n');
	}

	return 0;
}