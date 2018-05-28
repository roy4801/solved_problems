#include <iostream>
#include <cstring>

using namespace std;

#define SIZE 50

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int searchStr(char *s, const dir, const char word[])
{
	int offset;
	int compare = strlen(word);
	char *now = s;

	switch(dir)
	{
		case UP: // - 50 *sizeof(char)
		{
			offset = -50 * sizeof(char);
		}
		break;

		case DOWN: // 50 * sizeof(char)
		{
			offset = 50 * sizeof(char);
		}
		break;

		case LEFT: // - sizeof(char)
		{
			offset = -sizeof(char);
		}
		break;

		case RIGHT: // sizeof(char)
		{
			offset = sizeof(char);

			for(int i = 0; i < SIZE - compare; i++)
			{
				int cp = 0;
				for(int j = 0; j < compare; j++)
				{
					if(*now == word[j])
					{
						cp++;
						now += offset;
					}
					else
					{
						break;
					}
				}

				if(cp == compare)
				{
					return now - compare;
				}
			}
		}
		break;
	}
}

bool searchHorizontally(char m[50][50])
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{

		}
	}
}

bool searchVertically(char m[50][50])
{

}

bool searchDiagonlly(char m[50][50])
{

}

int main()
{

	printf("%d\n", searchStr());

	// char m[50][50];

	// int cases;

	// scanf("%d ", &cases);

	// while(cases--)
	// {
	// 	int row, col;
	// 	int test;

	// 	scanf("%d %d ", &row, &col);

	// 	// Get char map
	// 	for(int i = 0; i < row; i++)
	// 	{
	// 		for(int j = 0; j < col; j++)
	// 		{
	// 			m[i][j] = getchar();
	// 		}
	// 		getchar();
	// 	}

	// 	scanf("%d", &test);
	// 	char word[100];

	// 	// Scan
	// 	for(int i = 0; i < test; i++)
	// 	{
	// 		scanf("%s", word);

	// 		for(int a = 0; i a < row; a++)
	// 		{
	// 			for(int b = 0; b < col; b++)
	// 			{
	// 				// Maybe start pos
	// 				if(tolower(m[a][b]) == tolower(word[i]))
	// 				{
	// 					for(int dir = 0; i d < 8; d++)
	// 					{
	// 						switch(dir)
	// 						{
	// 							case 0:
									
	// 						}
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	return 0;
}