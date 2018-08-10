/*
 * Uva 10324 - Zeros and Ones
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <cstdint>
#include <climits>

using namespace std;

#define DIGIT(x) ((int64_t)1 << (int64_t)(x-1))

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10324.in", "r", stdin);
	freopen("./testdata/10324.out", "w", stdout);
	#endif
	int64_t str[16000];
	int read, cases;

	do
	{
		read = 1;
		int a, b;
		char c;

		while((c = getchar()) != '\n')
		{
			str[(read-1) / 64] |= ( c == 0 ? 0 : DIGIT(read) );
			read++;
		}

		printf("Read: %d\n", read);
		// scanf("%d", &cases);

		// while(cases-- && scanf("%d %d", &a, &b) != EOF)
		// {
		// 	bool flag[2] = {false};

		// 	a++;
		// 	b++;

		// 	flag[0] = str[a / 64] & DIGIT(a);
		// 	flag[1] = str[b / 64] & DIGIT(b);
			
		// 	if(flag[0] && flag[1])
		// 	{
		// 		printf("Yes\n");
		// 	}
		// 	else if(!flag[0] && !flag[1])
		// 	{
		// 		printf("No\n");
		// 	}
		// }
	}
	while(read != 0);

	return 0;
}