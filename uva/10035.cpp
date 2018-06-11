/*
 * Uva 10035 - Primary Arithmetic
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10035.in", "r", stdin);
	freopen("./testdata/10035.out", "w", stdout);
	#endif
	int a, b;

	while(scanf("%d %d", &a, &b) != EOF)
	{
		if(a == 0 && b == 0)
			break;

		int up = a > b ? a : b;
		int down = a > b ? b : a;
		int count = 0;
		bool carry = false;

		while(up > 0)
		{
			if(carry)
			{
				if(down % 10 + up % 10 > 8)
				{
					count++;
					carry = true;
				}
				else
				{
					carry = false;
				}
			}
			else
			{
				if(down % 10 + up % 10 > 9)
				{
					count++;
					carry = true;
				}
			}

			up /= 10;
			down /= 10;
		}

		if(count == 0)
		{
			printf("No carry operation.\n");
		}
		else
		{
			printf("%d carry ", count);

			if(count == 1)
			{
				printf("operation.\n");
			}
			else
			{
				printf("operations.\n");
			}
		}
	}

	return 0;
}