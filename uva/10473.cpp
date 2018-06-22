/*
 * Uva 10473 - Simple Base Conversion
 * author: roy8041
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10473.in", "r", stdin);
	freopen("./testdata/10473.out", "w", stdout);
	#endif
	char num[11];
	int n;

	while(scanf("%10s", num) != EOF)
	{
		if(num[0] == '0' && num[1] == 'x') // hex
		{
			sscanf(num, "%X", &n);
			printf("%d\n", n);
		}
		else
		{
			sscanf(num, "%d", &n);

			if(n < 0)
				break;
			printf("0x%X\n", n);
		}
	}

	return 0;
}
