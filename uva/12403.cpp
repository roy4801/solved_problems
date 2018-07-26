/*
 * Uva 12403 - Save Setu
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12403.in", "r", stdin);
	freopen("./testdata/12403.out", "w", stdout);
	#endif
	int oper;
	char opt, c;
	int money, total = 0;

	scanf("%d ", &oper);

	while(oper--)
	{
		scanf("%c", &opt);
		// printf("%c", opt);

		switch(opt)
		{
			case 'd':
				// Extracting chars until touching a space
				while(getchar() != ' ');

				scanf("%d ", &money);

				total += money;
			break;

			case 'r':
				printf("%d\n", total);

				// Exetacting the whole line of remaining str. It stops at '\n' or EOF
				while((c = getchar()) != '\n' && c != EOF);
			break;

			default:
				printf("Not handle\n");
			break;
		}
	}

	return 0;
}