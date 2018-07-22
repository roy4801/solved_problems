/*
 * Uva 12439 - February 29
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

bool isLeapYear(const int y)
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12439.in", "r", stdin);
	freopen("./testdata/12439.out", "w", stdout);
	#endif
	int y, d;
	char mstr[15];
	int cases, i = 1;

	scanf("%d", &cases);

	while(cases--)
	{
		int leap[2] = {0};

		for(int i = 0; i < 2 && scanf("%s %d, %d", mstr, &d, &y) != EOF; i++)
		{
			if(!i)
			{
				if(isLeapYear(y))
				{
					if((mstr[0] == 'J' && mstr[1] == 'a') || (mstr[0] == 'F'))
						y--;
				}
			}
			else
			{
				if(isLeapYear(y))
				{
					if((mstr[0] == 'J' && mstr[1] == 'a') || (mstr[0] == 'F' && d < 29) )
						y--;
				}
			}
			leap[i] = y / 4 - y / 100 + y / 400;
		}

		printf("Case %d: ", i++);
		printf("%d\n", leap[1] - leap[0]);

	}

	return 0;
}