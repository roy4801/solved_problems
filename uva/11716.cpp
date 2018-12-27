/*
 * Uva 11716 - Digital Fortress
 * author: roy4801
 * AC(C++)
 */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11716.in", "r", stdin);
	freopen("./testdata/11716.out", "w", stdout);
	#endif

	int cases;
	char str[10001]; // > 10000 => WA in C++

	if(scanf("%d ", &cases) != EOF)
	{
		while(cases--)
		{
			fgets(str, 10000, stdin);

			int length = strlen(str) - 1;
			if(str[length] == '\n')
			{
				str[length] = '\0';
			}
			else
				length++;

			// Judge int
			double rot = sqrt(length);
			// if rot is integer
			if(rot - (double)((int)rot) == 0.0)
			{
				int a = (int)rot;

				for(int i = 0; i < rot; i++)
				{
					for(int j = 0; j < rot; j++)
					{
						printf("%c", str[i+j * a]);
					}
				}
				putchar('\n');
			}
			else
			{
				printf("INVALID\n");
			}
		}
	}
	return 0;
}