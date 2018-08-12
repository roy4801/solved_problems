/*
 * Uva 12478 - Hardest Problem Ever (Easy)
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

char target[8][10] =
{
	"RAKIBUL",
	"ANINDYA",
	"MOSHIUR",
	"SHIPLU",
	"KABIR",
	"SUNNY",
	"OBAIDA",
	"WASI"
};

char s[][10] =
{
	"OBIDAIBKR",
	"RKAULHISP",
	"SADIYANNO",
	"HEISAWHIA",
	"IRAKIBULS",
	"MFBINTRNO",
	"UTOYZIFAH",
	"LEBSYNUNE",
	"EMOTIONAL"
};
const int col = sizeof(s) / sizeof(*s), row = strlen(*s);

int t[8][26];
int times[8];

void buildCharAppear()
{
	static bool init = false;

	if(!init)
	{
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < strlen(target[i]); j++)
			{
				t[i][target[i][j] - 'A']++;
			}
		}
		init = true;
	}
}

#define ALPHA 26

bool match(int lhs[], int rhs[])
{
	for(int i = 0; i < ALPHA; i++)
	{
		if(lhs[i] != rhs[i])
			return false;
	}
	return true;
}

void search()
{
	buildCharAppear();

	for(int i = 0; i < 8; i++)
	{
		// printf("i: %d\n", i);
		int len = strlen(target[i]);
		// printf("%d\n", len);

		// search the rows
		for(int a = 0; a < col; a++)
		{
			// printf("%d %d %d\n", col, row, len);
			for(int b = 0; b < row - len + 1; b++)
			{
				int alpha[26] = {0};
				for(int w = b; w < b + len; w++)
				{
					// printf("%c", s[a][w]);
					alpha[s[a][w] - 'A']++;
				}

				if(match(alpha, t[i]))
				{
					times[i]++;
					// printf(" X");
				}
				// putchar('\n');
			}
		}

		// search the columns
		for(int a = 0; a < row; a++)
		{
			for(int b = 0; b < col - len + 1; b++)
			{
				int alpha[26] = {0};
				for(int w = b; w < b + len; w++)
				{
					// printf("%c", s[w][a]);
					alpha[s[w][a] - 'A']++;
				}

				if(match(alpha, t[i]))
				{
					times[i]++;
					// printf(" X");
				}

				// putchar('\n');
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12478.in", "r", stdin);
	freopen("./testdata/12478.out", "w", stdout);
	#endif
	search();
	
	for(int i = 0; i < 8; i++)
	{
		if(times[i] == 2)
			printf("%s\n", target[i]);
	}
	
	return 0;
}