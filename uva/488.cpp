#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("488.in", "r", stdin);
	freopen("488.out", "w", stdout);
	#endif

	int freq, magn;
	int times;

	// for(;;)
	{
		if(scanf("%d\n\n%d\n%d", &times, &magn, &freq) != EOF)
		{
			while(freq--)
			{
				for(int i = 0; i < magn; i++)
				{
					for(int j = 0; j < i + 1; j++)
						printf("%d", i + 1);
					putchar('\n');
				}
				for(int i = magn - 1; i > 0; i--)
				{
					for(int j = 0; j < i ; j++)
						printf("%d", i);
					putchar('\n');
				}
				if(freq - 1 != 0)
				{
					putchar('\n');
				}
			}
		}
	}

	return 0;
}