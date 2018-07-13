/*
 * Uva 10550 - Combination Lock
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10550.in", "r", stdin);
	freopen("./testdata/10550.out", "w", stdout);
	#endif
	int pos, comb[3];


	while(scanf("%d %d %d %d", &pos, &comb[0], &comb[1], &comb[2]) != EOF)
	{
		if(!pos && !comb[0] && !comb[1] && !comb[2])
			break;

		int deg = 0;

		deg += 360 * 3;
		
		if(pos > comb[0])
			deg += 9 * (pos - comb[0]);
		else if(pos < comb[0])
			deg += 9 * (40 - (comb[0] - pos));

		if(comb[0] > comb[1])
			deg += 9 * (40 - (comb[0] - comb[1]));
		else if(comb[0] < comb[1])
			deg += 9 * (comb[1] - comb[0]);

		if(comb[1] > comb[2])
			deg += 9 * (comb[1] - comb[2]);
		else if(comb[1] < comb[2])
			deg += 9 * (40 - (comb[2] - comb[1]));
		

		printf("%d\n", deg);
	}

	return 0;
}