/*
 * Uva 10370 - Above Average
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10370.in", "r", stdin);
	freopen("./testdata/10370.out", "w", stdout);
	#endif
	int cases, people, tmp;
	float avg, percent;

	scanf("%d", &cases);

	while(cases--)
	{
		scanf("%d", &people);

		int grade[people];

		avg = percent = 0.f;

		for(int i = 0; i < people; i++)
		{
			scanf("%d", &grade[i]);

			avg += (float)grade[i];
		}

		avg /= (float)people;

		for(int i = 0; i < people; i++)
		{
			if((float)grade[i] > avg)
			{
				percent += 1.f;
			}
		}
		percent /= (float)people;

		printf("%.3f%%\n", percent * 100.f);
	}

	return 0;
}
