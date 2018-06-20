/*
 * Uva 10922 - 2 the 9s
 * author: roy4801
 * AC(C++) 0.0000
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

char d[1001];
bool first = true;

bool testMultipleOfNine(char num[], int &count)
{
	int mul = 0;

	if(first)
	{
		strcpy(d, num);

		first = false;
	}
	
	// Calc mul
	for(int i = 0; i < strlen(d); i++)
	{
		if(isdigit(d[i]))
		{
			mul += d[i] - '0';
		}
	}

	if(mul % 9 == 0)
	{
		count++;

		if(mul == 9)
		{
			return false;
		}
		else
		{
			// build next d
			int digit = 0;

			while(mul > 9)
			{
				d[digit++] = mul % 10 + '0';
				mul /= 10;
			}
			d[digit++] = mul + '0';
			d[digit] = '\0';

			return true;
		}
	}
	else
	{
		return false;
	}

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10922.in", "r", stdin);
	freopen("./testdata/10922.out", "w", stdout);
	#endif
	char in[1001];

	while(scanf("%s", in) != EOF && strcmp(in, "0") != 0)
	{
		int count = 0;

		while(testMultipleOfNine(in, count));

		if(count == 0)
		{
			printf("%s is not a multiple of 9.\n", in);
		}
		else
		{
			printf("%s is a multiple of 9 and has 9-degree %d.\n", in, count);
		}

		first = true;
	}

	return 0;
}