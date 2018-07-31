/*
 * Uva 11679 - Sub-prime
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11679.in", "r", stdin);
	freopen("./testdata/11679.out", "w", stdout);
	#endif
	int bank, deb;

	while(scanf("%d %d", &bank, &deb) != EOF && bank && deb)
	{
		int monetary[bank];
		int debet, credit, val;

		for(int i = 0; i < bank; i++)
			scanf("%d", &monetary[i]);

		for(int i = 0; i < deb && scanf("%d %d %d", &debet, &credit, &val) != EOF; i++)
		{
			monetary[debet - 1] -= val;
			monetary[credit - 1] += val;
		}

		bool ecoCrysis = false;
		for(int i = 0; i < bank; i++)
		{
			if(monetary[i] < 0)
				ecoCrysis = true;
		}

		printf("%c\n", ecoCrysis ? 'N' : 'S');
	}

	return 0;
}