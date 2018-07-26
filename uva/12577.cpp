/*
 * Uva 12577 - Hajj-e-Akbar
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12577.in", "r", stdin);
	freopen("./testdata/12577.out", "w", stdout);
	#endif
	char head;
	int i = 1;

	while((head = getchar()) != '*')
	{
		printf("Case %d: ", i++);
		switch(head)
		{
			case 'H':
				printf("Hajj-e-Akbar\n");
			break;

			case 'U':
				printf("Hajj-e-Asghar\n");
			break;
		}

		while(getchar() != '\n');
	}

	return 0;
}