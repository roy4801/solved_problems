/*
 * Uva 11689 - Soda Surpler
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11689.in", "r", stdin);
	freopen("./testdata/11689.out", "w", stdout);
	#endif
	int cases;
	int junk, col, ex;
	
	scanf("%d", &cases);


	while(scanf("%d %d %d", &junk, &col, & ex) != EOF
		&& (junk || col || ex))
	{
		int drink = 0;
		junk += col;

		// keep exchanging the junk to soda and drink until not having enough junk
		while(junk >= ex)
		{
			int buy = junk / ex;
			junk -= buy * ex;
			drink += buy;
			junk += buy;
		}

		printf("%d\n", drink);
	}

	return 0;
}