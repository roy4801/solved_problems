/*
 * Uva 11204 - Musical instruments
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11204.in", "r", stdin);
	freopen("./testdata/11204.out", "w", stdout);
	#endif
	int cases;
	int inst, stu;

	scanf("%d", &cases);

	while(cases-- && scanf("%d %d", &inst, &stu) != EOF)
	{
		int repeat[inst];

		memset(repeat, 0, sizeof(int) * inst);

		for(int i = 0; i < stu; i++)
		{
			int p = 0, read = 0;;

			// Read priorities of each student. Stop at reading 1
			while(scanf("%d", &p) != EOF && ++read && p != 1);

			// Count that how many 1s in each column.
			repeat[read-1]++;
			
			while(inst - read++ > 0)
			{
				// read other unnecessary inputs
				scanf("%d", &p);
			}
		}

		int comb = 1;
		for(int i = 0; i < inst; i++)
		{
			// If the number of 1s in each comumn is greater than one,
			// multiply them up ,and so we get the combination.
			comb *= repeat[i] > 1 ? repeat[i] : 1;
		}

		printf("%d\n", comb);
	}

	return 0;
}