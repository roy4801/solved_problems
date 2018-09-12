#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("p5.in", "r", stdin);
	freopen("p5.out", "w", stdout);
	#endif
	int cases, len;
	int up[50005], down[50005];

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &len) != EOF)
	{
		int bigger = 0;

		for(int i = 0; i < len; i++)
			scanf("%d", &up[i]);
		for(int i = 0; i < len; i++)
			scanf("%d", &down[i]);

		sort(up, up + len);
		sort(down, down + len);

		for(int i = 0; i < len; i++)
		{
			int *idx = lower_bound(down, down + len, up[i]);

			bigger += idx - down;
			
		}
		printf("%d\n", bigger);
	}

	return 0;
}