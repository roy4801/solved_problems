/*
 * Uva 10340 - All in All
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
// #include <cstring>
#include <string>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10340.in", "r", stdin);
	freopen("./testdata/10340.out", "w", stdout);
	#endif
	// char orig[100], encoded[100];
	string orig, encoded;
	int nowC = 0;

	// while(scanf("%s %s", orig, encoded) != EOF)
	while(cin >> orig >> encoded)
	{
		for(int i = 0; i < encoded.length(); i++)
		{
			if(orig[nowC] == encoded[i])
			{
				// printf("%c %c %d %d\n", orig[nowC], encoded[i], nowC, i);
				nowC++;

				if(nowC == orig.length())
					break;
			}
		}

		if(nowC == orig.length())
			printf("Yes\n");
		else
			printf("No\n");

		nowC = 0;
	}

	return 0;
}