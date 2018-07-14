/*
 * Uva 11369 - Shopaholic
 * author: roy4801
 * AC(C++) 0.010
 */
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11369.in", "r", stdin);
	freopen("./testdata/11369.out", "w", stdout);
	#endif
	int cases, num;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &num) != EOF)
	{
		int p[num], discount = 0;

		for(int i = 0; i < num; i++)
			scanf("%d", &p[i]);
		
		sort(p, p + num, greater<int>());

		int count = 0;
		for(int i = 0; i < num; i++)
		{
			if(++count == 3)
			{
				discount += p[i];
				count = 0;
			}
		}

		printf("%d\n", discount);
	}

	return 0;
}