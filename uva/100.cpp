#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/100.in", "r", stdin);
	freopen("./testdata/100.out", "w", stdout);
	#endif
	int i, j;

	while(scanf("%d %d", &i, &j) != EOF)
	{
		int max = -1;
		for(int s = (i > j ? j : i); s <= (i > j ? i : j); s++)
		{
			int times = 1, n = s;

			while(n != 1)
			{
				
				if(n % 2 != 0)
				{
					n *= 3;
					n += 1;
				}
				else
				{
					n /= 2;
				}
				times++;
			}

			if(max < times)
			{
				max = times;
			}
		}

		printf("%d %d %d\n", i, j, max);
	}
	return 0;
}