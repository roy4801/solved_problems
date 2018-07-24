/*
 * Uva 11559 - Event Planning
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11559.in", "r", stdin);
	freopen("./testdata/11559.out", "w", stdout);
	#endif
	int people, hotel, budget, week;

	while(scanf("%d %d %d %d", &people, &budget, &hotel, &week) != EOF)
	{
		bool pass[hotel];
		int totalCost[hotel];
		int money, bed;

		for(int i = 0; i < hotel; i++)
			pass[i] = true;

		// printf("Want: budget <= %d; week >= %d\n", budget, week);

		for(int a = 0; a < hotel; a++)
		{
			scanf("%d", &money);

			totalCost[a] = money * people;

			if(totalCost[a] > budget)
				pass[a] = false;

			// ckeck whether the hotel have enough beds in each weekends
			// must be >= 1 week
			int badWeek = 0;
			for(int i = 0; i < week; i++)
			{
				scanf("%d", &bed);

				if(bed < people)
					badWeek++;
			}
			if(badWeek == week)
				pass[a] = false;

			// printf("h #%d: %d %d %c\n", a, totalCost[a], badWeek, pass[a] ? 'T' : 'F');
		}

		// Find the smallest cost in hotels
		int minCost = 500001;
		bool allFail = true;
		
		for(int i = 0; i < hotel; i++)
		{
			if(pass[i] && minCost > totalCost[i])
			{
				minCost = totalCost[i];
				allFail = false;
			}
		}

		if(!allFail)
			printf("%d\n", minCost);
		else
			printf("stay home\n");
	}

	return 0;
}