/*
 * Uva 12503 - Robot Instructions
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12503.in", "r", stdin);
	freopen("./testdata/12503.out", "w", stdout);
	#endif
	int cases, num;

	scanf("%d", &cases);

	while(cases-- && scanf("%d ", &num) != EOF)
	{
		int pos = 0;
		int inst[num], n = 0;
		char c;

		memset(inst, 0, sizeof(int) * num);

		for(int i = 0; i < num; i++)
		{
			while((c = getchar()) != '\n' && c != EOF)
			{
				// Left
				if(c == 'L')
				{
					pos--;
					inst[n++] = -1;
				}
				// Right
				else if(c == 'R')
				{
					pos++;
					inst[n++] = 1;
				}
				// Same as X
				else if(c == 'S')
				{
					int space = 0, idx;

					while(space < 2)
					{
						c = getchar();

						if(c == ' ')
							space++;
					}

					scanf("%d", &idx);

					pos += inst[idx - 1];
					inst[n++] = inst[idx - 1];
				}
			}
		}

		printf("%d\n", pos);
	}

	return 0;
}