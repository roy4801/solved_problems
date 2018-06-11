/*
 * Uva 10144 - Expression
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

void overflowBit(int n)
{
	if(n < 0)
	{
		return;
	}
	else
	{
		if(n != 0)
		{
			putchar('('); // L30
			printf("(A%d|B%d)|(", n, n); // L 33
			overflowBit(n - 1);
		}
	}

	if(n != 0)
	{
		printf("|("); // L 32

		printf("(A%d|A%d)|(B%d|B%d)", n, n, n, n);
		
		putchar(')'); // L 28
		putchar(')'); // L 21
		putchar(')'); // L 15
	}
	else
	{
		printf("((A%d|B%d)|(A%d|B%d))", n, n, n, n);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10144.in", "r", stdin);
	freopen("./testdata/10144.out", "w", stdout);
	#endif
	int test, n;
	bool first = true;

	scanf("%d ", &test);

	while(test-- && scanf("%d", &n) != EOF)
	{
		if(!first)
			putchar('\n');

		overflowBit(n-1);
		putchar('\n');

		first = false;
	}
	return 0;
}