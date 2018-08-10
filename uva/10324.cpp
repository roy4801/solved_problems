/*
 * Uva 10324 - Zeros and Ones
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <cstdint>
#include <climits>

using namespace std;

#define DIGIT(x) ((int64_t)1 << (int64_t)((x)-1))

void printBit(int64_t n)
{
	for(int i = 0; i < 64; i++)
	{
		printf("%lld", n & (int64_t)DIGIT(64) ? 1LL : 0LL);
		n <<= 1LL;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10324.in", "r", stdin);
	freopen("./testdata/10324.out", "w", stdout);
	#endif
	// int read = 0;
	// while(read < 1000)
	// {
	// 	printBit(DIGIT((read+1) % 64));
	// 	printf(" %d\n", read++);
	// }

	int64_t str[16000] = {0};
	int read, cases;
	// int n = 1;

	do
	{
		read = 0;
		int a, b;
		char c;

		while((c = getchar()) != '\n')
		{
			str[read / 64] |= (c == '0' ? 0LL : DIGIT((read+1) % 64));
			read++;
		}
		
		scanf("%d", &cases);

		while(cases-- && scanf("%d %d", &a, &b) != EOF)
		{
			// printf("%d %d\n", a, b);
			bool flag[2] = {false};

			flag[0] = (str[a / 64] & DIGIT(a+1)) ? true : false;
			flag[1] = (str[b / 64] & DIGIT(b+1)) ? true : false;
			
			printf("Flag: %c %c\n", flag[0] ? 'T' : 'F', flag[1] ? 'T' : 'F');
			if((flag[0] && flag[1]) || (!flag[0] && !flag[1]))
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
	while(read != 0);

	return 0;
}