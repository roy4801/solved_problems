/*
 * Uva 11479 - Is this the easiest problem?
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11479.in", "r", stdin);
	freopen("./testdata/11479.out", "w", stdout);
	#endif
	int cases;
	int side[3];
	int64_t sum;

	scanf("%d", &cases);

	for(int i = 0; i < cases && scanf("%d %d %d", &side[0], &side[1], &side[2]) != EOF; i++)
	{
		printf("Case %d: ", i+1);

		sort(side, side + 3);

		sum = (int64_t)side[0] + (int64_t)side[1];

		if(side[0] <= 0 || side[1] <= 0 || side[2] <= 0)
		{
			printf("Invalid\n");
			continue;
		}


		if(side[0] == side[1]
		&& side[1] == side[2])
		{
			printf("Equilateral\n");
		}
		else if(sum > (int64_t)side[2])
		{
			if(side[0] == side[1] || side[1] == side[2] || side[0] == side[2])
			{
				printf("Isosceles\n");
			}
			else
				printf("Scalene\n");
		}
		else
			printf("Invalid\n");

	}

	return 0;
}