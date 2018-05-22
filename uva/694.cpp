/*
 * Uva 694 - The Collatz Sequence
 * author: roy4801
 * AC(c++) 0.010
 */
#include <iostream>
#include <climits>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/694.in", "r", stdin);
	freopen("./testdata/694.out", "w", stdout);
	#endif
	long long int init;
	int limit, nowcase = 0;

	while(scanf("%lld%d", &init, &limit) != EOF && init > 0LL && limit > 0 && limit <= INT_MAX)
	{
		// printf("%lld %d\n", init, limit);
		printf("Case %d: A = %lld, limit = %d, ", ++nowcase, init, limit);
		int term = 1;
		while(init != 1)
		{
			// odd
			if(init % 2LL != 0LL)
			{
				init *= 3LL;
				init += 1LL;
			}
			else
			{
				init /= 2LL;
			}

			if(init <= (long long int)limit)
			{
				++term;
			}
			else
				break;

		}
		printf("number of terms = %d\n", term);
	}

	return 0;
}