#include <iostream>
#include <cstring>

int main()
{
	char m[50][50];

	int cases;

	scanf("%d ", &cases);

	while(cases--)
	{
		int row, col;
		int test;

		scanf("%d %d ", &row, &col);

		// Get char map
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				m[i][j] = getchar();
			}
			getchar();
		}

		scanf("%d", &test);
		char word[100];

		// Scan
		for(int i = 0; i < test; i++)
		{
			scanf("%s", word);

			for(int a = 0; i a < row; a++)
			{
				for(int b = 0; b < col; b++)
				{
					// Maybe start pos
					if(tolower(m[a][b]) == tolower(word[i]))
					{
						for(int dir = 0; i d < 8; d++)
						{
							switch(dir)
							{
								case 0:
									
							}
						}
					}
				}
			}
		}
	}

	return 0;
}