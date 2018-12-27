/*
 * Uva 11292 - Dragon of Loowater
 * author: roy4801
 * AC(C++)
 */
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{
//	freopen("p11292.in", "r", stdin);

	int dragon, knight;
	int money = 0, exit = 1;
	
	while(scanf("%d %d", &dragon, &knight) != EOF)
	{
		if(dragon == 0 && knight == 0)
			return 0;

		int headHeight[dragon], knightHeight[knight];
		for(int i = 0; i < dragon; i++)
		{
			scanf("%d", &headHeight[i]);
		}
		for(int i = 0; i < knight; i++)
		{
			scanf("%d", &knightHeight[i]);
		}

		if(dragon > knight)
		{
			printf("Loowater is doomed!\n");
			continue;
		}

		std::sort(headHeight, headHeight + dragon);
		std::sort(knightHeight, knightHeight + knight);

		int killed = 0, money = 0;
		
		if(headHeight[dragon - 1] > knightHeight[knight - 1])
		{
			// Can't win
			goto last; //jmp line 57
		}
		else
		{
			for(int i = 0; i < dragon; i++)
			{
				for(int j = 0; j < knight; j++)
				{
					if(knightHeight[j] != -1)
					{
						if(headHeight[i] <= knightHeight[j]) // knight wins
						{
							killed++;
							money += knightHeight[j];
							knightHeight[j] = -1;
							break;
						}
						else
						{
							continue;
						}
					}
				}
				if(killed == dragon)
					break;
			}
		}
		
last:
		if(killed == dragon)
		{
			printf("%d\n", money);
		}
		else {
			printf("Loowater is doomed!\n");
		}
	}
}