/*
 * Uva 489 - Hangman Judge
 * author: roy4801
 * AC(c++) 0.030
 */
#include <iostream>

using namespace std;

#define FIRST 0
#define SECOND 1

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/489.in", "r", stdin);
	freopen("./testdata/489.out", "w", stdout);
	#endif
	
	char in[100];
	int round;

	while(scanf("%d", &round) != EOF && round != -1)
	{
		bool alpha[2][26] = {false};
		int failed = 0, good = 0;

		printf("%s %d\n", "Round", round);
		scanf("%s", in);

		char c, *p = in;
		while((c = *p++))
		{
			if(!alpha[FIRST][c - 'a'])
				good++;
			alpha[FIRST][c - 'a'] = true;
		}
		// printf("%d\n", good);
		scanf("%s", in);

		int tmp = 0;
		p = in;
		while((c = *p++))
		{
			// putchar(c);

			// Not exist in second
			if(!alpha[SECOND][c - 'a'])
			{
				// Not guess
				if(alpha[FIRST][c - 'a'])
					tmp++;
				else
					failed++;

				alpha[SECOND][c - 'a'] = true;
			}
			// Win or loose before the whole game completed
			if(failed == 7 || tmp == good)
			{
				break;
			}
		}
		
		// printf("\n|%d %d %d|", tmp, good, failed);
		if(failed != 7)
		{
			if(tmp != good)
			{
				printf("You chickened out.\n");
			}
			else
			{
				printf("You win.\n");
			}
		}
		else
		{
			printf("You lose.\n");
		}
		// putchar('\n');
	}

	return 0;
}