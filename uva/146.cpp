/*
 * Uva 146 - ID Codes
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/146.in", "r", stdin);
	freopen("./testdata/146.out", "w", stdout);
	#endif
	char id[51], c;
	int n = 0;

	while((c = getchar()) != EOF && c != '#')
	{
		if(c == '\n')
		{
			if(next_permutation(id, id + n))
			{
				for(int i = 0; i < n; i++)
					putchar(id[i]);
				putchar('\n');
			}
			else
				printf("No Successor\n");

			n = 0;
		}
		else
			id[n++] = c;
	}

	return 0;
}