/*
 * Uva 12157 - Tariff Plan
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

const int charge[2] = {10, 15};
const int sec[2] = {30, 60};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12157.in", "r", stdin);
	freopen("./testdata/12157.out", "w", stdout);
	#endif
	int cases, call, dur, i = 1;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &call) != EOF)
	{
		printf("Case %d: ", i++);
		int fee[2] = {0};

		for(int i = 0; i < call && scanf("%d", &dur) != EOF; i++)
		{
			for(int a = 0; a < 2; a++)
			{
				fee[a] += (dur / sec[a] + 1) * charge[a];
			}
		}

		// printf("%d %d\n", fee[0], fee[1]);

		if(fee[0] < fee[1])
		{
			printf("Mile %d\n", fee[0]);
		}
		else if(fee[0] > fee[1])
		{
			printf("Juice %d\n", fee[1]);
		}
		else
			printf("Mile Juice %d\n", fee[0]);
	}

	return 0;
}