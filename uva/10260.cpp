/*
 * Uva 10260 - Soundex
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

#define toIdx(x) (x-'A')

void initMap(char m[])
{
	m[toIdx('B')] = m[toIdx('F')] = m[toIdx('P')] = m[toIdx('V')] = 1;
	m[toIdx('C')] = m[toIdx('G')] = m[toIdx('J')] = m[toIdx('K')] = m[toIdx('Q')] = m[toIdx('S')] = m[toIdx('X')] = m[toIdx('Z')] = 2;
	m[toIdx('D')] = m[toIdx('T')] = 3;
	m[toIdx('L')] = 4;
	m[toIdx('M')] = m[toIdx('N')] = 5;
	m[toIdx('R')] = 6;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10260.in", "r", stdin);
	freopen("./testdata/10260.out", "w", stdout);
	#endif
	char val[26] = {0};
	char c;
	int now = 0;

	initMap(val);

	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			putchar('\n');
			now = 0; // reset
		}
		else if(val[toIdx(c)] != now)
		{
			if(val[toIdx(c)] != 0)
				putchar('0' + val[toIdx(c)]);
			now = val[toIdx(c)];
		}

	}

	return 0;
}