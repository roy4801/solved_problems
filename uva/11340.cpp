/*
 * Uva 11340 - Newspaper
 * author: roy4801
 * AC(C++) 0.120
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11340.in", "r", stdin);
	freopen("./testdata/11340.out", "w", stdout);
	#endif
	int cases, letter, line;

	scanf("%d", &cases);

	while(cases--)
	{
		scanf("%d ", &letter);

		std::map<char, int> m;
		int tmpMoney, totalMoney = 0;
		char tmpLetter;

		for(int i = 0; i < letter && scanf("%c %d ", &tmpLetter, &tmpMoney) != EOF; i++)
		{
			m[tmpLetter] = tmpMoney;
		}

		// Reading the paragraphs
		int nowLine = 0;

		scanf("%d ", &line);

		while(nowLine < line)
		{
			tmpLetter = getchar();

			totalMoney += m[tmpLetter];

			if(tmpLetter == '\n' || tmpLetter == EOF)
				nowLine++;
		}

		printf("%d.%02d$\n", totalMoney / 100, totalMoney % 100);
	}

	return 0;
}