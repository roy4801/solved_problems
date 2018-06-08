#include <iostream>

using namespace std;

typedef long long int int_64;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11038.in", "r", stdin);
	// freopen("./testdata/11038.out", "w", stdout);
	#endif
	int_64 n, m;

	while(scanf("%lld %lld", &n, &m) != EOF && n != -1 && m != -1)
	{
		int_64 count = 0;

		for(int i = n; i <= m; i++)
		{
			int tmp = i;

			while(tmp > 9)
			{
				if(tmp % 10 == 0)
				{
					count++;
				}
				tmp /= 10;
			}
			if(tmp == 0)
				count++;
		}

		printf("%lld\n", count);
	}

	return 0;
}