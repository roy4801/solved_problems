/*
 * Uva 462 - Bridge Hand Evaluator
 * author: roy4801
 * AC(C++) 0.010
 */
#include <iostream>
#include <utility>
#include <cctype>
#include <vector>

using namespace std;

enum Card
{
	S_SPADES = 0,
	S_HEARTS,
	S_DIAMONDS,
	S_CLUBS,
	S_TOTAL
};

const char suitChar[S_TOTAL] = {'S', 'H', 'D', 'C'};

inline int getSuit(const char s)
{
	switch(s)
	{
		case 'S':
			return Card::S_SPADES;
		break;

		case 'H':
			return Card::S_HEARTS;
		break;

		case 'D':
			return Card::S_DIAMONDS;
		break;

		case 'C':
			return Card::S_CLUBS;
		break;
	}
}

inline int getNumber(const char n)
{
	if(isdigit(n))
		return n - '0';
	else if(n == 'A')
		return 1;
	else if(n == 'T')
		return 10;
	else if(n == 'J')
		return 11;
	else if(n == 'Q')
		return 12;
	else if(n == 'K')
		return 13;
}

void judgeGetPoint(int &sum, const int num)
{
	// get points
	switch(num)
	{
		case 1:
			sum += 4;
		break;

		case 13:
			sum += 3;
		break;

		case 12:
			sum += 2;
		break;

		case 11:
			sum += 1;
		break;
	}
}

void judgeFinal(int &sum, int &ignore, bool stop[], const bool s[][13], int nowStack[])
{
	for(int i = 0; i < 4; i++)
	{
		// subtract
		// 13
		if(s[i][12] && nowStack[i] == 1)
		{
			sum -= 1;
		}
		// 12
		if(s[i][11] && nowStack[i] <= 2)
		{
			sum -= 1;
		}
		// 11
		if(s[i][10] && nowStack[i] <= 3)
		{
			sum -= 1;
		}

		// rule 5, 6, 7
		if(nowStack[i] == 2)
		{
			ignore += 1;
		}
		else if(nowStack[i] == 1)
		{
			ignore += 2;
		}
		else if(nowStack[i] == 0)
		{
			ignore += 2;
		}

		// whether one suit stopped or not
		if(s[i][0]) // A
		{
			stop[i] = true;
		}
		else if(s[i][12] && nowStack[i] >= 2) // >= K + *
		{
			stop[i] = true;
		}
		else if(s[i][11] && nowStack[i] >= 3) // >= Q + * + *
		{
			stop[i] = true;
		}
	}
}

void judgeResult(const int sum, const int ignore, bool stop[], const bool s[][13], int nowStack[])
{
	if(sum >= 16 && stop[0] && stop[1] && stop[2] && stop[3])
	{
		printf("BID NO-TRUMP\n");
	}
	else
	{
		if(sum + ignore >= 14)
		{
			// Find the suit having largest number of cards
			int max = 0, idx = -1;

			for(int i = 0; i < S_TOTAL; i++)
			{
				if(max < nowStack[i])
				{
					max = nowStack[i];
					idx = i;
				}
			}

			printf("BID %c\n", idx == -1 ? '@' : suitChar[idx]);
		}
		else
		{
			printf("PASS\n");
		}
	}
}

void update(bool hand[][13], int nowStack[], int &sum, const int suit, const int num)
{
	judgeGetPoint(sum, num);
	hand[suit][num-1] = true;
	nowStack[suit]++;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/462.in", "r", stdin);
	freopen("./testdata/462.out", "w", stdout);
	#endif
	char in[2];

	while(scanf("%c%c", &in[0], &in[1]) != EOF)
	{
		bool hand[S_TOTAL][13] = {false};
		bool stop[S_TOTAL] = {false};
		int nowStack[Card::S_TOTAL] = {0};
		int sum = 0, ignore = 0;

		update(hand, nowStack, sum, getSuit(in[1]), getNumber(in[0]));
		getchar();

		for(int i = 0; i < 12; i++)
		{
			in[0] = getchar();
			in[1] = getchar();

			update(hand, nowStack, sum, getSuit(in[1]), getNumber(in[0]));

			getchar();
		}

		judgeFinal(sum, ignore, stop, hand, nowStack);
		judgeResult(sum, ignore, stop, hand, nowStack);

#if 0
		for(int i = 0; i < Card::S_TOTAL; i++)
		{
			printf("%d: ", i);
			for(int j = 0; j < 13; j++)
			{
				if(hand[i][j])
					printf("%d ", j+1);
			}
			putchar('\n');
		}

		for(int i = 0; i < 4; i++)
			printf("%c ", suitChar[i]);
		putchar('\n');
		for(int i = 0; i < 4; i++)
		{
			printf("%d ", nowStack[i]);
		}
		putchar('\n');
		for(int i = 0; i < 4; i++)
		{
			printf("%c ", stop[i] ? 'T' : 'F');
		}

		printf("\npoint: %d %d\n", sum, ignore);
#endif
	}

	return 0;
}