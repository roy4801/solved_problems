/*
 * Uva 10324 - Zeros and Ones
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <cstdint>
#include <climits>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10324.in", "r", stdin);
	freopen("./testdata/10324.out", "w", stdout);
	#endif
	int g[1000005];
	int now = 0;
	char c, prev;

	while((c = getchar()) != EOF && c != '\n')
	{
		if(now > 0)
		{
			if(c != prev)
			{
				now++;
			}
		}

		prev = c;
	}

	return 0;
}