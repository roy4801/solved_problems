/*
 * Uva 10050 - Hartals
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10050.in", "r", stdin);
	freopen("./testdata/10050.out", "w", stdout);
	#endif
	int cases, day;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &day) != EOF)
	{
		int party;

		scanf("%d", &party);

		int p[party], start = 1, week = 0, strike = 0;

		for(int i = 0; i < party && scanf("%d", &p[i]) != EOF; i++);

		while(start <= day)
		{
			for(int i = 0; i < party; i++)
				if(start % p[i] == 0 && week != 5 && week != 6)
				{
					// printf("w %d\n", week);
					strike++;
					break;
				}

			week++;

			if(week > 6)
				week = 0;

			start++;
		}

		printf("%d\n", strike);
	}

	return 0;
}