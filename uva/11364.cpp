/*
 * Uva 11364 - Parking
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11364.in", "r", stdin);
	freopen("./testdata/11364.out", "w", stdout);
	#endif
	int cases;
	int num;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &num) != EOF)
	{
		int store[num], distance = 0;

		for(int i = 0; i < num; i++)
		{
			scanf("%d", &store[i]);
		}
		
		sort(store, store + num);

		printf("%d\n", (store[num-1] - store[0]) * 2);
	}

	return 0;
}